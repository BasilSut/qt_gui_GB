#include "downloader.h"
#include <QNetworkReply>
#include <QDebug>

downloader::downloader(QObject *parent)
{
    pnam = new QNetworkAccessManager(this);
    connect(pnam, SIGNAL(finished(QNetworkReply *)),SLOT(slotFinished(QNetworkReply *)));
}



void downloader::download(const QUrl &html_page)
{
    QNetworkRequest request(html_page);
    QNetworkReply* reply = pnam->get(request);

    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),SIGNAL(downloadProgress(qint64,qint64)));

}

void downloader::download_pic(const QUrl &pic)
{
    QNetworkRequest request2(pic);
    QNetworkReply* reply_pic = pnam->get(request2);

    if(reply_pic->error()!= QNetworkReply::NetworkError::NoError){
        emit error();
    }
    else{

        emit done(reply_pic->url(), reply_pic->readAll());
    }
    reply_pic->deleteLater();
}

void downloader::slotFinished(QNetworkReply *reply)
{
    if(reply->error()!= QNetworkReply::NetworkError::NoError){
        emit error();
    }
    else{

        emit done(reply->url(), reply->readAll());
    }
    reply->deleteLater();
}

