#pragma once

#include <QMainWindow>
#include <QMdiArea>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void add_subwin();
    void about_to_quit();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();
protected:
    void closeEvent(QCloseEvent* event) override;

private:
    Ui::MainWindow *ui;
    QMdiSubWindow* sw;
signals:
    void About_to_Q();
};

