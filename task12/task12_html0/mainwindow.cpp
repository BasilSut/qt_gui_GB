#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "downloader.h"
#include <QFile>
#include <QFileDevice>
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include <QTextStream>
#include <QtXml>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar_2->setValue(0);
    m_downloader = new downloader(this);
    connect(ui->pushButton_go, SIGNAL(clicked()), SLOT(slotGo()));
    connect(m_downloader, SIGNAL(downloadProgress(qint64,qint64)), SLOT(slotDownloadProgress(qint64,qint64)));
    connect(m_downloader, SIGNAL( done(const QUrl&, const QByteArray&)), SLOT(slotDone(const QUrl&, const QByteArray&)));



    //connect(m_downloader, SIGNAL( downloadPIC(const QUrl&, const QByteArray&)), SLOT(slotDownloaded_Pic(const QUrl&, const QByteArray&)));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slotGo()
{
    m_downloader->download(QUrl(url_yandex+ui->txt->text())); //url_yandex+
}



void MainWindow::first_piture(QLabel *lablE){

        parser_line = QString(parser_array);

    int start = parser_line.indexOf(",\"url\":\"");
    int end = parser_line.indexOf(".jpg\"},", start);
    QString first_pic = parser_line.mid(start+8, end - start-4);//выделил первую картинку из HTML файла
//    if(first_pic.indexOf(",\"url\":\"",15)){
//        int new_start = first_pic.indexOf(",\"url\":\"");
//        first_pic  =first_pic.mid(new_start+8, end - start-4);
//    }
    qInfo()<<first_pic;
    parser_line = parser_line.indexOf(end);
    int start_s = parser_line.indexOf(",\"url\":\"");
    int end_s = parser_line.indexOf(".jpg\"},", start);
    QString second = parser_line.mid(start_s+8, end_s - start_s-4);
    qInfo()<<second;

    m_pic1 = new downloader(this);
    connect(m_pic1, SIGNAL(downloadProgress(qint64,qint64)), SLOT(slotDownloadProgress(qint64,qint64)));
    connect(m_pic1, SIGNAL( done(const QUrl&, const QByteArray&)), SLOT(slotDone(const QUrl&, const QByteArray&)));
    m_pic1->download(QUrl(first_pic));

//    m_pic2 = new downloader(this);
//    connect(m_pic2, SIGNAL(downloadProgress(qint64,qint64)), SLOT(slotDownloadProgress(qint64,qint64)));
//    connect(m_pic2, SIGNAL( done(const QUrl&, const QByteArray&)), SLOT(slotDownloaded_Pic(const QUrl&, const QByteArray&)));
//    m_pic2->download(QUrl(second));
}


void MainWindow::slotDownloadProgress(qint64 received, qint64 total)
{
//    if(total <=0){
//        slotError();
//        return;
//    }
    ui->progressBar_2->setValue(100*received/total);
}

void MainWindow::slotError()
{
    QMessageBox::critical(this, "Error", "Error!");
}


void MainWindow::slotDone(const QUrl &url, const QByteArray &ba)
{
    parser_array = ba;
    QFile file(url.path().section('/', -1));//последняя секция после слеша = имя файла
    if(file.open(QIODevice::WriteOnly)){
        file.write(ba);
        file.close();
    }

   //showPic(file.fileName(),*ui->label00);
    showPicture(file.fileName(),ui->label00);

}

void MainWindow::slotDownloaded_Pic(const QUrl &url, const QByteArray &ba)
{
    parser_array = ba;
    QFile file(url.path().section('/', -1));//последняя секция после слеша = имя файла
    if(file.open(QIODevice::WriteOnly)){
        file.write(ba);
        file.close();
    }

   //showPic(file.fileName(),*ui->label00);
    showPicture(file.fileName(),ui->label01);
}

void MainWindow::showPicture(const QString &path, QLabel *lablE)
{

    QPixmap pix(path);
    pix = pix.scaled( ui->label00->size());
     lablE->setPixmap(pix);
     lablE->show();
     if(pix.isNull()){
         first_piture(ui->label00);
     }

}


