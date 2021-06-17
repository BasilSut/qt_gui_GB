/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_loadHTML;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_1;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_USD;
    QLineEdit *lineEdit_EUR;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(434, 398);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout_3->addWidget(plainTextEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_loadHTML = new QPushButton(centralwidget);
        pushButton_loadHTML->setObjectName(QString::fromUtf8("pushButton_loadHTML"));

        horizontalLayout_2->addWidget(pushButton_loadHTML);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_1 = new QLabel(centralwidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        verticalLayout->addWidget(label_1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_USD = new QLineEdit(centralwidget);
        lineEdit_USD->setObjectName(QString::fromUtf8("lineEdit_USD"));
        lineEdit_USD->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_USD);

        lineEdit_EUR = new QLineEdit(centralwidget);
        lineEdit_EUR->setObjectName(QString::fromUtf8("lineEdit_EUR"));
        lineEdit_EUR->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_EUR);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 434, 21));
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
        pushButton_loadHTML->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "USD:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "EUR:", nullptr));
        lineEdit_USD->setPlaceholderText(QCoreApplication::translate("MainWindow", "USD", nullptr));
        lineEdit_EUR->setPlaceholderText(QCoreApplication::translate("MainWindow", "EUR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
