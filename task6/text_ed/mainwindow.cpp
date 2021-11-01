#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QPushButton>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QIODevice>
#include <QDebug>
#include <QCloseEvent>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Text Editor"));

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(add_subwin()));


    add_subwin();

}

MainWindow::~MainWindow()
{
    ui->mdiArea->closeAllSubWindows();
    delete ui;
}

void MainWindow::add_subwin()
{
    sw = new QMdiSubWindow( ui->mdiArea );
    sw->setWidget( new QTextEdit( sw ) );
    sw->setAttribute( Qt::WA_DeleteOnClose );
    ui->mdiArea->addSubWindow( sw );

    sw->show();

}

void MainWindow::about_to_quit()
{

}


void MainWindow::on_actionNew_triggered()
{
   ui->mdiArea->activeSubWindow()->setWindowTitle("new_file");
}


void MainWindow::on_actionOpen_triggered()
{


    //QString filter = "ALL File (*.*) ;; Text File(*.txt) ;; CPP File (*.cpp) ;; HPP File (*.h)";
    //QString file_name = QFileDialog::getOpenFileName(this,"Open a file", QDir::currentPath(),filter);
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file");
    QFileInfo fi(file_name);
    QFile file(file_name);
     qDebug()<<"s + "<<file_name;
    //sw->mdiArea()->activeSubWindow()->setWindowTitle(fi.baseName());
    //ui->mdiArea->activeSubWindow()->setWindowTitle(fi.baseName());
    qDebug()<<"v + "<<fi.baseName();
//    //

   if(!file.open(QIODevice::ReadOnly|QFile::Text)){
       QMessageBox::warning(this,"error", "file wasn't opened"+file.errorString());
       return;
   }
    QTextStream input_data(&file);

    QString txt = input_data.readAll();
    qDebug()<<txt;


    QWidget* cur_w = sw->widget();
    QTextEdit* textEdit = (QTextEdit*) cur_w;
    textEdit->append(txt);
    file.close();

}


void MainWindow::on_actionSave_As_triggered()
{

    QString file_name = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(file_name);

    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"error", "file wasn't saved"+file.errorString());
        return;
    }
    QTextStream output_data(&file);
    //ui->mdiArea->
    QWidget* cur_w = sw->widget();
    QTextEdit* saving_text = (QTextEdit*) cur_w;

    output_data<<saving_text->toPlainText();

    file.close();
}


void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle("Print");
    if (dlg.exec() != QDialog::Accepted)
        return;

}


void MainWindow::on_actionExit_triggered()
{
    emit About_to_Q();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox(this);
    msgBox.setText("Are you sure you want to close the editor?");
    msgBox.setIcon(QMessageBox::Icon::Question);
    msgBox.addButton("Yes",QMessageBox::YesRole);//0
    msgBox.addButton("No",QMessageBox::NoRole);

    int result = msgBox.exec();
    if(result==0){
        event->accept();
    }else if(result==1){
        event->ignore();
    }
}

