#pragma once

#include <QMainWindow>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QTranslator tra;


protected:
    //void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private slots:
    void on_pushButton_open_clicked();

    void on_pushButton_open_only_clicked();

    void on_pushButton_about_clicked();

    void on_pushButton_save_clicked();
/*
    void on_radioButton_ru_released();

    void on_radioButton_eng_released();
*/
private:
    void newFile();
    Ui::MainWindow *ui;
};

