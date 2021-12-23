#pragma once
#include <downloader.h>
#include <QMainWindow>
#include <QProgressBar>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    downloader* m_downloader;
    downloader* m_pic1;
    downloader* m_pic2;

    QProgressBar *ppb;
    QLineEdit*txt;
    QPushButton *button;
    QString url_yandex = "https://yandex.by/images/search?mode=xml&text=";

    QString parser_line;
    QByteArray parser_array;

    QNetworkAccessManager *manager;
    QNetworkRequest request;

    void showPicture(const QString&, QLabel *);
    void showPic(const QString&);
    void first_piture(QLabel *lablE);

private slots:
    void slotGo();
    void slotError();
    void slotDownloadProgress(qint64,qint64);
    void slotDone(const QUrl&url, const QByteArray&);
    void slotDownloaded_Pic(const QUrl&url, const QByteArray&);



};

