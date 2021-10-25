#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDir>
#include<QMessageBox>
#include <QTextStream>
#include <QtHelp/QtHelp>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    //ui->radioButton_eng->clicked(true);
    ui->pushButton_open->setText(tr("Open file"));
    ui->pushButton_open_only->setText(tr("Open only"));
    ui->pushButton_about->setText(tr("About this programm"));
    ui->pushButton_save->setText(tr("Save"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->modifiers() & Qt::ControlModifier){
        if(event->key() == Qt::Key_S)
           on_pushButton_save_clicked();
        if(event->key() == Qt::Key_O)
           on_pushButton_open_clicked();
        if(event->key() == Qt::Key_Q)
           //quit the programm _______________________________________
        if(event->key() == Qt::Key_N){
            //create a new file
            __________________________________________
        }
    }

}




void MainWindow::on_pushButton_open_clicked()
{
    QString filter = "ALL File (*.*) ;; Text File(*.txt) ;; CPP File (*.cpp) ;; HPP File (*.h)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file", QDir::currentPath(),filter);
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"error", "file wasn't opened");
    }
    QTextStream input_data(&file);
    QString txt = input_data.readAll();
    ui->plainTextEdit->setPlainText(txt);
    ui->plainTextEdit->setReadOnly(false);
    ui->pushButton_save->setDisabled(false);

    file.close();
}


void MainWindow::on_pushButton_open_only_clicked()
{
    QString filter = "ALL File (*.*) ;; Text File(*.txt) ;; CPP File (*.cpp) ;; HPP File (*.h)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file", QDir::currentPath(),filter);
    QFile file(file_name);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"error", "file wasn't opened");
    }
    QTextStream input_data(&file);
    QString txt = input_data.readAll();
    ui->plainTextEdit->setPlainText(txt);
    ui->plainTextEdit->setReadOnly(true);
    ui->pushButton_save->setDisabled(true);

    file.close();
}


void MainWindow::on_pushButton_about_clicked()
{
    QFile about_file(":/xml/build_test_editor/about.xml");
        if(!about_file.open(QIODevice::ReadOnly | QIODevice::Text)){
             QMessageBox::warning(this,"error", "file wasn't opened");
        } else {
             QTextStream input_data(&about_file);
             QString txt = input_data.readAll();

             QMessageBox help_Box;
             help_Box.setTextFormat(Qt::RichText); // для ссылки на сайт
             help_Box.setText(txt);
             help_Box.exec();
        }
}


void MainWindow::on_pushButton_save_clicked()
{
    QString filter = "ALL File (*.*) ;; Text File(*.txt) ;; CPP File (*.cpp) ;; HPP File (*.h)";
    QString file_name = QFileDialog::getSaveFileName(this,"Open a file",QDir::currentPath(), filter);
    QFile file(file_name);

    if(!file.open(QIODevice::ReadWrite | QFile::Text)){
        QMessageBox::warning(this,"error", "file wasn't saved");
    }
    QTextStream output_data(&file);
    QString txt =ui->plainTextEdit->toPlainText();
    output_data<<txt;

    file.close();
}

/*
void MainWindow::on_radioButton_ru_released()
{
    tra.load(":/qm/text_editor_ru_RU.qm");
}


void MainWindow::on_radioButton_eng_released()
{
    tra.load(":/qm/text_editor_eng_ENG.qm");
}
*/
