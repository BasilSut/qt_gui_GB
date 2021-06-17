#include "mainwindow.h"
#include <QTranslator>

#include <QApplication>

int main(int argc, char *argv[])
	{
		QApplication a(argc, argv);
        QTranslator tr;
        tr.load("G:/tr/QtLanguage_ru.qm");
        a.installTranslator(&tr);
        MainWindow w;
		w.show();
		return a.exec();
	}
