#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    titles_of_menuBar();
    createActions();
    createMenus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::new_file()
{

}

void MainWindow::createActions(){

    newAction = fileMenu->addAction(tr("&New"));
    connect(newAction,SIGNAL(triggered()),this,SLOT(new_file()));

    openAction = fileMenu->addAction(tr("&Open"));
    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));

    saveAction = fileMenu->addAction(tr("&Save"));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));

    saveAsAction = fileMenu->addAction(tr("&Save &As..."));
    connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveAs()));

    exitAction = fileMenu->addAction(tr("&Exit"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(about_to_exit()));
    //exitAction->setCheckable(true);
    //exitAction->setChecked(true);


    copy_A = formatting->addAction(tr("&Copy"));
    connect(copy_A,SIGNAL(triggered()),this,SLOT(copy_slot()));
    past_A = formatting->addAction(tr("&Past"));
    connect(past_A,SIGNAL(triggered()),this,SLOT(past_slot()));
    cut_A = formatting->addAction(tr("&Cut"));
    connect(cut_A,SIGNAL(triggered()),this,SLOT(cut_slot()));

    copy_format_A = formatting->addAction(tr("&Сopy format"));
    connect(copy_format_A,SIGNAL(triggered()),this,SLOT(copy_format_slot()));
    left_alignment_A = formatting->addAction(tr("&Left alignment"));
    connect(left_alignment_A,SIGNAL(triggered()),this,SLOT(left_alignment_slot()));
    right_alignment_A = formatting->addAction(tr("&Right alignment"));
    connect(right_alignment_A,SIGNAL(triggered()),this,SLOT(right_alignment_slot()));
    center_alignment_A = formatting->addAction(tr("&Center alignment"));
    connect(center_alignment_A,SIGNAL(triggered()),this,SLOT(center_alignment_slot()));

    set_font_A = new QAction(tr("&Set Font"));
    //set_font_A->setShortcut(tr("Ctrl+F"));
    //set_font_A->setStatusTip(tr("Exit the application"));
    connect(set_font_A, SIGNAL(triggered()), this, SLOT(set_fond()));


    aboutAction = aboutQt->addAction(tr("AboutQt"));
    connect(aboutAction,SIGNAL(triggered()),qApp, SLOT(aboutQt()));
}
void MainWindow::createMenus(){


    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    formatting->addAction(copy_A);
    formatting->addAction(past_A);
    formatting->addAction(cut_A);
    formatting->addSeparator();
    formatting->addAction(copy_format_A);
    formatting->addAction(left_alignment_A);
    formatting->addAction(right_alignment_A);
    formatting->addAction(center_alignment_A);
    formatting->addSeparator();
    formatting->addAction(set_font_A);


}

void MainWindow::open(){

}


void MainWindow::save(){

}

void MainWindow::saveAs()
{

}

void MainWindow::about_to_exit()
{

}

void MainWindow::copy_slot()
{

}

void MainWindow::past_slot()
{

}

void MainWindow::cut_slot()
{

}

void MainWindow::copy_format_slot()
{

}

void MainWindow::left_alignment_slot()
{

}

void MainWindow::right_alignment_slot()
{

}

void MainWindow::center_alignment_slot()
{

}

void MainWindow::set_fond()
{

}



void MainWindow::titles_of_menuBar()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    formatting = menuBar()->addMenu(tr("&Format"));
    aboutQt = menuBar()->addMenu(tr("&AboutQt"));
}
