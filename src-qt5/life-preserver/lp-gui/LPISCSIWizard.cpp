#include "LPISCSIWizard.h"
#include "ui_LPISCSIWizard.h"

#include <pcbsd-utils.h>

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QTemporaryFile>
#include <QTimer>

LPISCSIWizard::LPISCSIWizard(QWidget *parent, QString zpool) : QWizard(parent), ui(new Ui::LPISCSIWizard()){
  ui->setupUi(this); //load the designer form
  success = false;
  //Need random numbers later - initialize the random number generator
  qsrand( QDateTime::currentMSecsSinceEpoch() );
  randList = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYAZ!@#$%^&,.?:";
  //Load the initial values into the UI
  if(zpool.isEmpty()){
    //no input pool given, probe for all pools available
    
  }else{
    //Force only the input zpool (no probing)
    ui->combo_zpool->addItem(zpool);
  }
  // - Time schedule options
  ui->combo_schedule->addItem(tr("On New Snapshot"), "sync");
  ui->combo_schedule->addItem(tr("Manually Started"), "manual");
  ui->combo_schedule->addItem(tr("Daily"), "daily");
  ui->combo_schedule->addItem(tr("Hourly"), "hour");
  ui->combo_schedule->addItem(tr("Every 30 Minutes"), "30min");
  ui->combo_schedule->addItem(tr("Every 10 Minutes"), "10min");
  
  //Setup the signals/slots
  connect(this, SIGNAL(currentIdChanged(int)), this, SLOT(CheckPage()) );
  connect(ui->combo_schedule, SIGNAL(currentIndexChanged(int)), this, SLOT(CheckPage()) );
  connect(ui->group_encryptData, SIGNAL(toggled(bool)), this, SLOT(CheckPage()) );
  connect(ui->line_datapass, SIGNAL(textChanged(const QString&)), this, SLOT(CheckPage()) );
  connect(ui->line_keypass, SIGNAL(textChanged(const QString&)), this, SLOT(CheckPage()) );
  connect(ui->line_keypass2, SIGNAL(textChanged(const QString&)), this, SLOT(CheckPage()) );
  connect(ui->tool_getLPS, SIGNAL(clicked()), this, SLOT(FindLPSfile()) );
  connect(ui->tool_findGELI, SIGNAL(clicked()), this, SLOT(FindGELIKeyFile()) );
  connect(ui->push_savekey, SIGNAL(clicked()), this, SLOT(GenerateKeyFile()) );
}

LPISCSIWizard::~LPISCSIWizard(){
	
}

// =============
//    PRIVATE SLOTS
// =============
void LPISCSIWizard::CheckPage(){
  bool canback = false;
  bool canforward = false;
  switch(this->currentId()){
    case 0: //Intro page - nothing to check
      canforward = true;
      saveAttempted = false;
      break;
    case 1: //server config
      canback = true; //nothing behind
      canforward = !ui->label_LPSfile->whatsThis().isEmpty(); //need a *.lps file selected
      saveAttempted = false;
      break;
    case 2: //local config
      canback = true; //nothing special behind to prevent back/forth
      canforward = !ui->group_encryptData->isChecked() || !ui->line_datapass->text().isEmpty();
      ui->time_schedule->setVisible( ui->combo_schedule->currentData().toString()=="daily" );
      saveAttempted = false;
      break;
    case 3: //wait page (replication settings being saved)
      canback = saveAttempted;
      canforward = false; //Never allow the user to go forward past this page
      break;
    case 4: //Save key page (last one)
      canback = false; //never go back - is already setup
      canforward = !ui->push_savekey->isEnabled(); //enable the finish button if the key file was created
      break;
  }
  //Setup the back button
  if(this->button(QWizard::BackButton)->isVisible()){ 
    this->button(QWizard::BackButton)->setEnabled(canback); }
  //The next/finish buttons are mutually exclusive
  if(this->button(QWizard::NextButton)->isVisible()){ 
    this->button(QWizard::NextButton)->setEnabled(canforward); }
  else if(this->button(QWizard::FinishButton)->isVisible()){ 
    this->button(QWizard::FinishButton)->setEnabled(canforward); }
    
  //Special Case - the wait page was just shown (ask to start process)
  if(this->currentId()==3){
   QApplication::processEvents();
   if(QMessageBox::Yes == QMessageBox::question(this->window(), tr("Ready to begin"), tr("Are to ready to enable off-site data storage?")+"\n\n"+tr("This may take a few moments..."),QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) ){
      QTimer::singleShot(0, this, SLOT(enableReplication()) );
    }else{
      this->back(); //Go back to setup
    }
  }
}

void LPISCSIWizard::enableReplication(){
  //Get all the inputs
  QString zpool = ui->combo_zpool->currentText();
  QString timeschedule = ui->combo_schedule->currentData().toString();
    if(timeschedule=="daily"){ timeschedule = ui->time_schedule->time().toString("HH"); }
  QString lpsfilepath = ui->label_LPSfile->whatsThis();
  bool encrypt = ui->group_encryptData->isChecked();
    
  //Assemble the command to run
  QString cmd = "lpreserver replicate add iscsi \"%1\" \"%2\" \"%3\"";
  cmd = cmd.arg(lpsfilepath, zpool, timeschedule);
  if(encrypt){
    cmd.append(" \""+ui->line_datapass->text()+"\"");
  }
  //Run the command
  QString log = pcbsd::Utils::runShellCommand(cmd, success).join("\n");
  cmd.clear(); //make sure to clear this ASAP so that the password (if any) gets cleared
  //Now parse the results
  QString keyfile = log.section("\nKey: ",1,1).section("\n",0,0).simplified();
  if(!QFile::exists(keyfile)){ keyfile.clear(); }
    if(success || !keyfile.isEmpty()){
      //Go to the next page directly
      this->next(); //this bypasses the status of the "next" button (so we can leave it disabled in the UI)
    }else{
      //Show a message box about the failure with any details possible
      QString msg = tr("The Life Preserver experienced an error when trying to setup this remote backup. Please verify that your settings are accurate and try again.");
      QMessageBox dlg(QMessageBox::Warning, tr("Error With Settings"), msg, QMessageBox::Ok, this);
        dlg.setDetailedText(log);
      dlg.exec();
      this->back();
    }
}

void LPISCSIWizard::FindGELIKeyFile(){
  QString file = QFileDialog::getOpenFileName(this, tr("Select GELI Key File"), "/var/db/lpreserver/keys", tr("GELI Key Files (*.key)") );
  if(file.isEmpty()){ return; }
  else{ ui->line_datapass->setText(file); }
}

void LPISCSIWizard::RandomizeEncKey(){
  int nums = 30+(qrand()%21); //30->50 characters long
  QString key;
  for(int i=0; i<nums; i++){
    //Pull a random character from the list and place it in a random spot in the string
    key.append( randList[ (qrand()%randList.length()) ] );
    //key = key.insert( qrand()%key.length(), randList[ (qrand()%randList.length()) ] );
  }
  ui->line_datapass->setText(key);	
}

void LPISCSIWizard::GenerateKeyFile(){
  //First get all the inputs
  QString zpool = ui->combo_zpool->currentText();
  QString host = ui->label_LPShost->text();
  bool setpass = ui->group_keypass->isChecked();
  if(setpass){
    //ensure that the password lines are the same and not empty
    if(ui->line_keypass->text().isEmpty() || (ui->line_keypass->text()!=ui->line_keypass2->text()) ){
      QMessageBox::warning(this, tr("Invalid Passwords"), tr("The passwords listed either do not match or are blank"));
      return;
    }
  }
  //Assemble the command
  QString cmd = "lpreserver replicate saveiscsi \"%1\" \"%2\"";
  cmd = cmd.arg(zpool, host);
  QTemporaryFile TF("/tmp/.XXXXXXXXXXXXXXXXXXXXXXXX");
  if(setpass){
    //lpreserver need the password input via a file - use a temporary file
    TF.open();
    QTextStream out(&TF);
      out << ui->line_keypass->text();
    TF.close();
    cmd.append(" \""+TF.fileName()+"\"");
  }
  //Now run the command (note: file saved into current working Dir
  bool ok = false;
  QString cdir = QDir::currentPath();
  QDir::setCurrent("/usr/home"); //save the file here
  QString log = pcbsd::Utils::runShellCommand(cmd, ok).join("\n");
  QDir::setCurrent(cdir); //put it back to what it was before
  qDebug() << "ISCSIsave log:" << log;
  //Now parse the output
  if(!ok){
    QString msg = tr("The Life Preserver experienced an error when trying to create your key file. Please verify that your settings are accurate and try again.");
      QMessageBox dlg(QMessageBox::Warning, tr("Error Creating Key"), msg, QMessageBox::Ok, this);
        dlg.setDetailedText(log);
      dlg.exec();
  }else{
    QMessageBox::information(this, tr("Key Created"), tr("Your key file has been successfully created and is located in /usr/home") );
  }
  ui->push_savekey->setEnabled(!ok);
  CheckPage();
}

void LPISCSIWizard::FindLPSfile(){
  //Prompt the user to select a LPS file
  static QString lastdir = QDir::homePath();
  QString filepath = QFileDialog::getOpenFileName(this, tr("Select LPS file"), lastdir, tr("Life Preserver Server File (*.lps *.LPS)"));
  if(filepath.isEmpty()){ return; } //cancelled
  ui->label_LPSfile->setWhatsThis(filepath);
  ui->label_LPSfile->setText(filepath.section("/",-1));
  //Now load the file and put it's value into the UI for inspection
  QStringList info = pcbsd::Utils::readTextFile(filepath).split("\n");
  for(int i=0; i<info.length(); i++){
    if(info[i].startsWith("ihost:")){ ui->label_LPShost->setText(info[i].section(": ",1,1)); }
    else if(info[i].startsWith("ipassword:")){ ui->label_LPSpass->setText(info[i].section(": ",1,1)); }
    else if(info[i].startsWith("iuser:")){ ui->label_LPSuser->setText(info[i].section(": ",1,1)); }
    else if(info[i].startsWith("itarget:")){ ui->label_LPStarget->setText(info[i].section(": ",1,1)); }
  }
  CheckPage();
}

