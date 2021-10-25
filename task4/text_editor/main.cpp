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
        const QString baseName = "text_editor_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    QTranslator traRu,traEng;
    traRu.load(":/qm/text_editor_ru_RU.qm");
    traEng.load(":/qm/text_editor_eng_ENG.qm");

    a.installTranslator(&traEng);
    MainWindow w;
    w.setWindowTitle(MainWindow::tr("Text Editor"));
    w.show();
    return a.exec();
}
