#include <QFileDialog>
#include <QTextStream>
#include<QMessageBox>
#include <QDir>
#include <QtHelp/QtHelp>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_o_file_clicked()
{
    QString filter = "ALL File (*.*) ;; Text File(*.txt) ;; CPP File (*.cpp) ;; HPP File (*.h)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file", QDir::currentPath(),filter);
    //QMessageBox::information(this,"..", file_name);
    QFile file(file_name);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"error", "file wasn't opened");
    }
    QTextStream input_data(&file);
    QString txt = input_data.readAll();
    ui->plainTextEdit->setPlainText(txt);
    file.close();
}


void MainWindow::on_save_clicked()
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

void MainWindow::on_about_clicked()
{
    QFile about_file("about.xml");
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
