#include <stdio.h>
#include "MainClient.h"
#include <QCoreApplication>
#include <unistd.h> //for getlogin()

MainClient::MainClient(QObject *parent) : QObject(parent){
  curSock = new QLocalSocket(this);
    connect(curSock, SIGNAL(connected()), this, SLOT(startRequest()));
    connect(curSock, SIGNAL(disconnected()), this, SLOT(requestFinished()) );
    connect(curSock, SIGNAL(error(QLocalSocket::LocalSocketError)), this, SLOT(connectionError()));
}

MainClient::~MainClient(){
}

bool MainClient::parseInputs(QStringList inputs){
  userRequest = inputs;
  if(inputs.isEmpty() || inputs.contains("-h") || inputs.contains("--help") ){ ShowUsage(); return false;}
  //Convert the user request into server request formatting
  servRequest << inputs;
  
  //Now start the connection to the server
  curSock->connectToServer("/var/run/pc-sysconfig.pipe", QIODevice::ReadWrite | QIODevice::Text);
  return true;
}

void MainClient::ShowUsage(){
  qDebug() << "pc-sysconfig: Simple system configuration utility";
  qDebug() << "Usage: \"pc-sysconfig <command 1> <command 2> ...\"";
  qDebug() << "Available Information Commands:";
  qDebug() << " \"list-remdev\": List all removable devices attached to the system.";
  qDebug() << " \"list-mounteddev\": List all removable devices that are currently mounted";
  qDebug() << " \"list-audiodev\": List all available audio devices";
  qDebug() << " \"supportedfilesystems\": List all the filesystems that are currently detected/supported by pc-sysconfig";
  qDebug() << " \"devinfo <device> [skiplabel]\": Fetch device information (Filesystem, Label, Type)";
  qDebug() << " \"devsize <device>\": Fetch device space (must be mounted)";
  qDebug() << "\"usingtormode\": [TRUE/FALSE] Returns whether the system is routing all traffic through TOR\n";
  qDebug() << "\"getscreenbrightness\": Returns the brightness of the first controllable screen as a percentage (0-100) or \"[ERROR]\" otherwise\n";
  qDebug() << "\"systemcansuspend\": [TRUE/FALSE] Returns whether the system supports the S3 suspend state\n";
  qDebug() << "\nAvailable Action Commands:";
  qDebug() << " \"mount <device> [<filesystem>] [<mountpoint>]\":";
  qDebug() << "  -- This will mount the removable device on the system (with user-accessible permissions if the mountpoint needs to be created)";
  qDebug() << "  -- If there is no filesystem set (or \"auto\" is used), it will try to use the one that is auto-detected for the device";
  qDebug() << "  -- If there is no mountpoint set, it will assign a new mountpoint within the \"/media/\" directory based on the device label\n";
  qDebug() << " \"unmount <device or mountpoint> [force]\":";
  qDebug() << "  -- This will unmount the removable device from the system";
  qDebug() << "  -- This may be forced by using the \"force\" flag as well (not recommended for all cases)";
  qDebug() << "  -- If the input device is a memory disk (/dev/md*), then it will automatically remove the memory disk from the system as well\n";
  qDebug() << " \"load-iso <absolute path to the *.iso file>\":";
  qDebug() << "  -- This will load the ISO file as a memory disk on the system (making it available for mounting/browsing)\n";
  qDebug() << " \"setdefaultaudiodevice <pcm device>\":";
  qDebug() << "  -- This will set the given pcm device (I.E. \"pcm3\") as the default audio output device\n";
  qDebug() << " \"setscreenbrightness <percentage>\":";
  qDebug() << "  -- This will set the brightness of all the available screens to the given percentage\n"; 
  qDebug() << "  -- It is also possible to adjust the current value by supplying a [+/-] before the number\n"; 
  qDebug() << "  -- For example: using \"+5\" as the percentage will increase the brightness by 5% for each screen\n"; 
  qDebug() << "  -- This returns \"[ERROR]\" or \"[SUCCESS]\" based on whether the change could be performed\n"; 
  qDebug() << "\"suspendsystem\": Puts the system into the suspended state (S3)\n";
}

void MainClient::startRequest(){
  QString username = QString(getlogin());
  QString locale = QString(getenv("LANG")).section(".",0,0);
  if(locale.isEmpty()){ locale = QString(getenv("LC_ALL")).section(".",0,0); }
  QTextStream out(curSock);
  out << "[USERNAME]"+username+"\n";
  out << "[LANG]"+locale+"\n";
  out << servRequest.join("\n");
  out << "\n[FINISHED]";
  connect(curSock, SIGNAL(readyRead()), this, SLOT(requestFinished()) );
}

void MainClient::requestFinished(){
  static bool running = false;
  if(running){ return; } //already reading stream
  //qDebug() << "Client Request Finished";
  QTextStream in(curSock);
  bool finished = false;
  static QString line = "";
  running = true;
  while(!in.atEnd()){
    QString newline = in.readLine();
    //qDebug() << "newline:" << newline << "line:" << line;
    if(newline.startsWith("[") && !line.isEmpty()){
      //qDebug() << "Printed Line:" << line;
      fprintf(stdout, "%s\n", qPrintable(line) );
      line.clear();
      if(newline.startsWith("[INFOSTART]")){
	newline = newline.remove(0,11); //remove that internal flag 
      }
    }else if(newline.startsWith("[INFOSTART]") && line.isEmpty()){
	newline = newline.remove(0,11); //remove that internal flag 
    }
    line.append(newline);
    if(line=="[FINISHED]"){ finished=true; break;}
  }
  running = false;
  if(finished){
    curSock->disconnectFromServer();
    QCoreApplication::exit(0);
  }
}

void MainClient::connectionError(){
  qDebug() << "Client Connection Error:";
  if(curSock->error()==QLocalSocket::PeerClosedError){
    //requestFinished();
  }else{
    qDebug() << "[ERROR]" << curSock->errorString();
    qDebug() << " - Is the pc-sysconfig daemon running?";
  }
  exit(1);
}
