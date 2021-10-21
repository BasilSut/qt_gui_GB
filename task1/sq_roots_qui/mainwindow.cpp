#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
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


void MainWindow::on_pushButton_clicked()
{
    QString str_a, str_b, str_c;
     double a, b, c, x, x2;
     a = ui->lineEdit_a->text().toDouble();
     b = ui->lineEdit_b->text().toDouble();
     c = ui->lineEdit_c->text().toDouble();


     if(a!=0){
         if((b*b - 4*a*c) >= 0) //D>0
             {
                 x =( -1*b - qSqrt(b*b - 4*a*c) ) / (2 * a);
                 //cout << "First root equals: " << x << endl;

                 x2 = ( -1*b + qSqrt(b*b - 4*a*c) ) / (2 * a);
                 //cout << "Second root equals: " << x2 << endl;
                 QString x_str = "First root equals:\t" +QString::number(x)+
                                 "\nSecond root equals:\t"+ QString::number(x2);
                 ui->textEdit_out->setText(x_str);
             }
             else
             {
                 QString d_less = "The discriminant is less than 0, the roots are imaginary.\n";
                 ui->textEdit_out->setText(d_less);
                //cout << "The discriminant is less than 0, the roots are imaginary." << endl;
             }
     }else{
         QString a0 = "a = 0, it is not an quadratic equation!\n";
         ui->textEdit_out->setText(a0);
         //cout<<"a = 0, it is not an quadratic equation!";
     }


}

