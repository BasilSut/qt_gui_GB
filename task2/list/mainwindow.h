#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

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

    void on_pushB_choose_clicked();


    void on_pushButton_add_clicked();



    void on_lineEdit_textChanged();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
