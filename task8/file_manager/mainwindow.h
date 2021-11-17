#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include "controller.h" // Подключаем класс-контроллер

class MainWindow : public QMainWindow
{   
Q_OBJECT

public:
   MainWindow(QWidget *parent = 0);
   ~MainWindow();
private:
   QLineEdit *searchEdit;
   QPushButton *startFindButton;
   QTextEdit *infoText;
   QComboBox *selDrive;
   Controller *controllerl;
   QLabel *statusLabel;
private slots:
   void findFileSlot();
   void changStatusLabel(QString);
   void printFindFile(QString);
};

