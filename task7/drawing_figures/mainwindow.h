#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "blockscheme.h"
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QMouseEvent *eve_check;
    QGraphicsScene *scence;
    BlockScheme *bscheme;
protected:
   // void mouseReleaseEvent(QMouseEvent *event) override; как разделить реализацию из BlockScheme и из MainWindow
private slots:
    //void init();
    void reDraw();
    void randomColourF();



};
