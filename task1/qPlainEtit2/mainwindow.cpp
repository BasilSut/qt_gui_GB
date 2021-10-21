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


void MainWindow::on_pushButton_copy_clicked()
{
    QString copy = ui->plainTextEdit_1->toPlainText();//get text from widget
    ui->plainTextEdit_2->appendPlainText(copy);
}


void MainWindow::on_pushButton_repl_clicked()
{
    QString repl = ui->plainTextEdit_1->toPlainText();//get text from widget
    ui->plainTextEdit_2->setPlainText(repl);
}


void MainWindow::on_pushButton_html_clicked()
{
    QString html = "<font colour='green'>Hello</font>";
    ui->plainTextEdit_2->appendHtml(html);
}

