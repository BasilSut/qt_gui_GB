#pragma once
#include <QMainWindow>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushB_add_show_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QString current_data, current_name, current_progress;
    QRegExp rx;

    bool validations();
    bool createConnection();
    bool createTable();
    bool insertTask(QString name="", QString date="", QString progress="");
    void printTableToGUI();

};

