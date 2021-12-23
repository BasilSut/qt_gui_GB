#pragma once

#include <QObject>
#include <QNetworkAccessManager>

class downloader : public QObject
{
    Q_OBJECT
public:
    explicit downloader(QObject *parent = nullptr);
    void download(const QUrl&);
    void download_pic(const QUrl&);

signals:
    void downloadProgress(qint64,qint64);
    void downloadPIC(const QUrl&, const QByteArray&);
    void done(const QUrl&, const QByteArray&);
    void error();
private slots:
    void slotFinished(QNetworkReply*);
private:
    QNetworkAccessManager* pnam;
};









