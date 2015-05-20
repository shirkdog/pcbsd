#include <QApplication>
#include <qtranslator.h>
#include <qlocale.h>
#include <pcbsd-SingleApplication.h>
#include <QDebug>
#include <QMessageBox>
#include <QSplashScreen>
#include <QProcess>
#include <QTextCodec>

#include "mainUI.h"
#include "migrateUI.h"

#include <unistd.h>
#include <sys/types.h>

//#include "../config.h"
#ifndef PREFIX
#define PREFIX QString("/usr/local")
#endif

int main( int argc, char ** argv )
{
    //Check for root permissions
    if( getuid() != 0){
      qDebug() << "pc-softwaremanager must be started as root!";
      return system("pc-su pc-softwaremanager");
    }
    qDebug() << "Starting Up the AppCafe";
    PCSingleApplication a(argc, argv);   
    if ( !a.isPrimaryProcess() ){
      qDebug() << " - an instance of the AppCafe is already running";
      return 0;
    }

    QTranslator translator;
    QLocale mylocale;
    QString langCode = mylocale.name();
    if ( ! QFile::exists( PREFIX + "/share/pcbsd/i18n/SoftwareManager_" + langCode + ".qm" ) )
      langCode.truncate(langCode.indexOf("_"));
    translator.load( QString("SoftwareManager_") + langCode, PREFIX + "/share/pcbsd/i18n/" );
    a.installTranslator( &translator );
    qDebug() << "Locale:" << langCode;
    QTextCodec::setCodecForLocale( QTextCodec::codecForName("UTF-8") ); //Force Utf-8 compliance
    
    //Check for the old PBI system, and prompt to migrate if needed
    QDir dir("/var/db/pbi/installed");
    if( !dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot).isEmpty() ){
      QPixmap pix(":/icons/splash.png");
      QSplashScreen SS(0, pix,  Qt::WindowStaysOnTopHint);
	SS.showMessage(QObject::tr("Updating Index"), Qt::AlignHCenter | Qt::AlignBottom);
	SS.show();
	a.processEvents();
	a.processEvents();
	if ( QProcess::execute("pbi_updateindex") != 0 )
        {
	  QMessageBox::critical( 0, QObject::tr("Failed to update index!"), QObject::tr("Failed to contact the index server. Please check your network connection before trying to install / update applications."));
	}
      //Still on the old system - prompt to migrate to PBI-NG
      MigrateUI w;
      w.show();
      SS.finish(&w);
      QObject::connect(&a, SIGNAL(InputsAvailable(QStringList)), &w, SLOT(slotSingleInstance()) );
      a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
      return a.exec();
    }else{
      //Already on PBI-NG
      MainUI w; 
      w.ProgramInit();
      if(argc >= 3 && QString(argv[1])=="-jail"){
	QString jailname = argv[2];
	qDebug() << " - Loading Jail:" << jailname;
        w.showJail( jailname );
      }
      w.show();

      QObject::connect(&a, SIGNAL(InputsAvailable(QStringList)), &w, SLOT(slotSingleInstance()) );
      a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
      return a.exec();
    }
}
