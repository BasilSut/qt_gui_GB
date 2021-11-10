#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)

{
    srand(clock());
    scence = new QGraphicsScene(this);
    setScene(scence);
    bscheme = new BlockScheme(this);

    scence->addItem(bscheme);



    connect(bscheme, SIGNAL(reDraw()),this,SLOT(reDraw()));
    connect(bscheme, SIGNAL(randomColourF),this,SLOT(randomColourF()));

}




MainWindow::~MainWindow()
{

}

//void MainWindow::mouseReleaseEvent(QMouseEvent *event)
//{
//    if(!eve_check->isAccepted()){
//        eve_check = event;
//        scence->addItem(bscheme);
//    }

//}

void MainWindow::reDraw()
{
    scence->update();
    update();
}

void MainWindow::randomColourF()
{
    bscheme->setBrush(QBrush(QColor(rand()%256,rand()%256,rand()%256)));
}

