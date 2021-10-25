/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QGridLayout *gridLayout;
    QPushButton *pushButton_open_only;
    QPushButton *pushButton_save;
    QPushButton *pushButton_about;
    QPushButton *pushButton_open;
    QRadioButton *radioButton_eng;
    QRadioButton *radioButton_ru;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(474, 370);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_open_only = new QPushButton(centralwidget);
        pushButton_open_only->setObjectName(QString::fromUtf8("pushButton_open_only"));

        gridLayout->addWidget(pushButton_open_only, 3, 0, 1, 1);

        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        gridLayout->addWidget(pushButton_save, 3, 1, 1, 1);

        pushButton_about = new QPushButton(centralwidget);
        pushButton_about->setObjectName(QString::fromUtf8("pushButton_about"));

        gridLayout->addWidget(pushButton_about, 0, 1, 1, 1);

        pushButton_open = new QPushButton(centralwidget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));

        gridLayout->addWidget(pushButton_open, 0, 0, 1, 1);

        radioButton_eng = new QRadioButton(centralwidget);
        radioButton_eng->setObjectName(QString::fromUtf8("radioButton_eng"));

        gridLayout->addWidget(radioButton_eng, 4, 1, 1, 1);

        radioButton_ru = new QRadioButton(centralwidget);
        radioButton_ru->setObjectName(QString::fromUtf8("radioButton_ru"));

        gridLayout->addWidget(radioButton_ru, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 474, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_open_only->setText(QCoreApplication::translate("MainWindow", "Open(only read)", nullptr));
        pushButton_save->setText(QCoreApplication::translate("MainWindow", "Save File", nullptr));
        pushButton_about->setText(QCoreApplication::translate("MainWindow", "About this programm", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        radioButton_eng->setText(QCoreApplication::translate("MainWindow", "Eng", nullptr));
        radioButton_ru->setText(QCoreApplication::translate("MainWindow", "Ru", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
