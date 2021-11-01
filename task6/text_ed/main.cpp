#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "text_ed_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    QObject::connect(&a, SIGNAL(aboutToQuit()), &w, SLOT(about_to_quit()));
     QObject::connect(&w, SIGNAL(About_to_Q()), &a, SLOT(quit()));
    w.show();
    return a.exec();
}
