#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createConnection();
    createTable();
    validations();

}

MainWindow::~MainWindow()
{
    delete ui;
}




bool MainWindow::createConnection(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("organizer.db");
    if(!db.open()){
        qDebug()<<"Cannot open database";
        return false;
    }
    return  true;
}


bool MainWindow::createTable()
{
    QSqlQuery query;
    QString s  = "CREATE TABLE organizer ("
                "taskId INTEGER NOT NULL,"
                "taskName TEXT,"
                "date TEXT,"
                "taskProgress INTEGER,"
                "PRIMARY KEY(taskId)"
                ");";
    if(!query.exec(s)){
        qDebug() << "Unable to create a table";
        return false;
    }
    return true;
}




bool MainWindow::insertTask(QString name, QString date, QString progress)
{
    QSqlQuery query;
    QString s = "INSERT INTO organizer (taskName, date, taskProgress) "
                "VALUES('%1','%2','%3');";
    QString q = s.arg(name).arg(date).arg(progress);
    if(!query.exec(q)){
        qDebug()<< "Unable to make insert operation!";
        return false;
    }
    return true;
}

void MainWindow::on_pushB_add_show_clicked()
{


    current_name = ui->lineE_name->text();
    current_data = ui->lineE_data->text();
    if (!rx.exactMatch(current_data)||current_name.isEmpty()){
        ui->label->setText("Invalid data");
        return;
    }
    //qDebug()<<rx.exactMatch(current_data);
    current_progress=QString::number(ui->spinBox->value());
    //qDebug()<<current_name<<current_data<<current_progress;
    insertTask(current_name,current_data,current_progress);
    printTableToGUI();
    ui->label->setText("Done!");
}



void MainWindow::printTableToGUI(){
    ui->tableView->reset();
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM organizer");
    ui->tableView->setModel(model);
}


bool MainWindow::validations()
{
    ui->spinBox->setRange(1,10);
    ui->lineE_name->setPlaceholderText("type a new task");
    ui->lineE_data->setPlaceholderText("00.00.2020");
    rx = QRegExp("^(?:[0-2]?[0-9]|3[0-1])\\.(?:[0]?[0-9]|1[0-2])\\.[2-9][0-9][2-9][0-9]$");
    QRegExpValidator *validator = new QRegExpValidator(this);
    validator->setRegExp(rx);
    ui->lineE_data->setValidator(validator);


}
