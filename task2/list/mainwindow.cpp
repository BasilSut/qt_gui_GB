#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    \


    //QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT());
    ui->setupUi(this);//G:/GB/Qt_GUI/task2/list/
    ui->listWidget->setIconSize(QSize(40,40));
    QListWidgetItem *ptr_1 = new QListWidgetItem(QIcon("G:/GB/Qt_GUI/task2/list/logoCpp.png"),"C++");
    ui->listWidget->addItem(ptr_1);
    ptr_1->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled );
    QListWidgetItem *ptr_2 = new QListWidgetItem(QIcon("G:/GB/Qt_GUI/task2/list/logoPy.png"),"Python");
    ui->listWidget->addItem(ptr_2);
    ptr_2->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled );
    QListWidgetItem *ptr_3 = new QListWidgetItem(QIcon("G:/GB/Qt_GUI/task2/list/logoJava.png"),"Java");
    ui->listWidget->addItem(ptr_3);
    ptr_3->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled );
    QListWidgetItem *ptr_4 = new QListWidgetItem(QIcon("G:/GB/Qt_GUI/task2/list/logoCsh.png"),"C#");
    ui->listWidget->addItem(ptr_4);
    ptr_4->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled );
    QListWidgetItem *ptr_5 = new QListWidgetItem(QIcon("G:/GB/Qt_GUI/task2/list/logoPHP.png"),"PHP");
    ui->listWidget->addItem(ptr_5);
    ptr_5->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled );
    QListWidgetItem *ptr_6 = new QListWidgetItem(QIcon("G:/GB/Qt_GUI/task2/list/logoJS.png"),"JavaScript");
    ui->listWidget->addItem(ptr_6);
    ptr_6->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled );


}

MainWindow::~MainWindow(){
    delete ui;
}








void MainWindow::on_pushB_choose_clicked(){
    ui->statusbar->showMessage(ui->listWidget->currentItem()->text());
}



void MainWindow::on_pushButton_add_clicked(){
    QString txt =  ui->lineEdit->text();
    QListWidgetItem *new_ptr = new QListWidgetItem(QIcon("G:/GB/Qt_GUI/task2/list/logoNew.png"),txt);
     ui->listWidget->addItem(new_ptr);
}




