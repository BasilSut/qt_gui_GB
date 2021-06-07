#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "parser.h"

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


void MainWindow::on_plainTextEdit_textChanged()
{
    QString txt =  ui->plainTextEdit->toPlainText();
    qint32 pos = 0;
    while(1){
        qint32 fnd =txt.indexOf("#@",pos);
        if(fnd == -1)
            return;
        pos = fnd + 1;
        int r = txt.indexOf("%",fnd);
        int space = txt.indexOf(" ", fnd);

        int rub = txt.indexOf("RUB",fnd);
        int eur = txt.indexOf("EUR",fnd);
        int auth = txt.indexOf("AUTH",fnd);
        int mille = txt.indexOf("MILL",fnd);
        int reg = txt.indexOf("REG",fnd);

        bool rr=(txt.indexOf("RUB",r)==rub);
        bool ee =(txt.indexOf("EUR",r)==eur);
        bool ar=(txt.indexOf("AUTH",r)==auth);
        bool mi =(txt.indexOf("MILL",r)==mille);
        bool rg =(txt.indexOf("REG",r)==reg);


        if((r < space || space == -1) && r != -1){


            if(!rr){
                        txt.insert(r+1,QString(" ₽"));
                        txt.remove(fnd,6);
                        ui->plainTextEdit->setPlainText(txt);

               }
            else if(!ee){
                txt.insert(r+1,QString(" €"));
                txt.remove(fnd,6);
                ui->plainTextEdit->setPlainText(txt);

            }
            else if(!ar){
                txt.insert(r+1,QString(" ©"));
                txt.remove(fnd,7);
                ui->plainTextEdit->setPlainText(txt);

            }
            else if(!mi){
                txt.insert(r+1,QString(" ‰"));
                txt.remove(fnd,7);
                ui->plainTextEdit->setPlainText(txt);
            }
            else if(!rg){
                txt.insert(r+1,QString(" ®"));
                txt.remove(fnd,6);
                ui->plainTextEdit->setPlainText(txt);
            }

        }
    }

}
