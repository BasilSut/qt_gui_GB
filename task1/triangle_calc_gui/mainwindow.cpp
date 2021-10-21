#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

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


void MainWindow::on_pushButton_calc_clicked()
{
    double A,B,C, alfa;
    A = ui->lineEdit_A->text().toDouble();
    B = ui->lineEdit_B->text().toDouble();
    alfa = ui->lineEdit_alfa->text().toDouble();
    if(ui->radioButton_grad->isChecked())
        alfa = alfa * M_PI/180;//to rad
    C = qSqrt(A*A+B*B+2*A*B * qCos(alfa));
    QString ans = "Сторона С = " + QString::number(C);
    ui->textEdit_out->setText(ans);

}

