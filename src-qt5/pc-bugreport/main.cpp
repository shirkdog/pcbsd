#include <QApplication>
#include <QFile>
#include <QString>
#include <QTranslator>
#include <QTextCodec>
//#include "pcbsd-ui.h"
#include "mainwindow.h"

#ifndef PREFIX
#define PREFIX QString("/usr/local")
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    QLocale mylocale;
    QString langCode = mylocale.name();
    if ( ! QFile::exists( PREFIX + "/share/pcbsd/i18n/pc-bugreport_" + langCode + ".qm" ) )
              langCode.truncate(langCode.indexOf("_"));
    translator.load( QString("pc-bugreport_") + langCode, PREFIX + "/share/pcbsd/i18n/" );
    a.installTranslator( &translator );
    QTextCodec::setCodecForLocale( QTextCodec::codecForName("UTF-8") ); //Force Utf-8 compliance
    MainWindow w;
    w.show();


    return a.exec();
}
