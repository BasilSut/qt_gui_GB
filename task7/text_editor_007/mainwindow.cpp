#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QClipboard>

#include <QDebug>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QIODevice>

#include <QFont>
#include <QFontDialog>
#include <QTextCursor>
#include <QBrush>
#include <QColor>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Text Editor"));
    titles_of_menuBar();
    createActions();
    createMenus();
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

   // connect(newAction, SIGNAL(triggered()), this, SLOT(add_subwin()));


    //add_sub_win();


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::createActions(){

    newAction = new QAction(tr("&New"));
    connect(newAction,SIGNAL(triggered()),this,SLOT(new_file()));

    openAction = new QAction(tr("&Open"));
    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));

    saveAction = new QAction(tr("&Save"));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));

    saveAsAction = new QAction(tr("&Save &As..."));
    connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveAs()));

    exitAction = new QAction(tr("&Exit"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(about_to_exit()));
    //exitAction->setCheckable(true);
    //exitAction->setChecked(true);


    copy_A = new QAction(tr("&Copy"));
    connect(copy_A,SIGNAL(triggered()),this,SLOT(copy_slot()));
    paste_A = new QAction(tr("&Past"));
    connect(paste_A,SIGNAL(triggered()),this,SLOT(past_slot()));
    cut_A = new QAction(tr("&Cut"));
    connect(cut_A,SIGNAL(triggered()),this,SLOT(cut_slot()));

    copy_format_A = new QAction(tr("&Сopy format"));
    connect(copy_format_A,SIGNAL(triggered()),this,SLOT(copy_format_slot()));
    paste_format_A = new QAction(tr("&Paste format"));
    connect(paste_format_A,SIGNAL(triggered()),this,SLOT(paste_format_slot()));
    left_alignment_A = new QAction(tr("&Left alignment"));
    connect(left_alignment_A,SIGNAL(triggered()),this,SLOT(left_alignment_slot()));
    right_alignment_A = new QAction(tr("&Right alignment"));
    connect(right_alignment_A,SIGNAL(triggered()),this,SLOT(right_alignment_slot()));
    center_alignment_A = new QAction(tr("&Center alignment"));
    connect(center_alignment_A,SIGNAL(triggered()),this,SLOT(center_alignment_slot()));

    set_font_A = new QAction(tr("&Set Font"));
    //set_font_A->setShortcut(tr("Ctrl+F"));
    //set_font_A->setStatusTip(tr("Exit the application"));
    connect(set_font_A, SIGNAL(triggered()), this, SLOT(set_fond()));


    aboutAction = aboutQt->addAction(tr("AboutQt"));//reminder: (the way on this line) vs aboutQt->addAction(aboutAction);
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
    formatting->addAction(paste_A);
    formatting->addAction(cut_A);
    formatting->addSeparator();
    formatting->addAction(copy_format_A);
    formatting->addAction(paste_format_A);
    formatting->addSeparator();
    formatting->addAction(left_alignment_A);
    formatting->addAction(right_alignment_A);
    formatting->addAction(center_alignment_A);
    formatting->addSeparator();
    formatting->addAction(set_font_A);


}

void MainWindow::new_file()
{

}

void MainWindow::open(){
    QString filter = "ALL File (*.*) ;; Text File(*.txt) ;; CPP File (*.cpp) ;; HPP File (*.h)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file", QDir::currentPath(),filter);
    //QString file_name = QFileDialog::getOpenFileName(this,"Open a file");
    QFileInfo fi(file_name);
    QFile file(file_name);

//    //

   if(!file.open(QIODevice::ReadOnly|QFile::Text)){
       QMessageBox::warning(this,"error", "file wasn't opened"+file.errorString());
       return;
   }
    QTextStream input_data(&file);

    QString txt = input_data.readAll();
    qDebug()<<txt;

    textEdit->append(txt);
    file.close();
}


void MainWindow::save(){

}

void MainWindow::saveAs()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(file_name);

    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"error", "file wasn't saved"+file.errorString());
        return;
    }
    QTextStream output_data(&file);

    output_data<<textEdit->toPlainText();

    file.close();
}

void MainWindow::about_to_exit()
{
        emit About_to_Q();
}

void MainWindow::copy_slot()
{
    buff_txt = textEdit->textCursor().selectedText();
    qApp->clipboard()->setText(buff_txt);
}

void MainWindow::past_slot()
{
    textEdit->textCursor().insertText(qApp->clipboard()->text());
}

void MainWindow::cut_slot()
{
    buff_txt = textEdit->textCursor().selectedText();
    qApp->clipboard()->setText(buff_txt);
    textEdit->textCursor().removeSelectedText();

}

void MainWindow::copy_format_slot()
{
    QTextCursor cursor = textEdit->textCursor();
    copy_of_text_format = cursor.blockFormat();
}

void MainWindow::paste_format_slot()
{
    QTextCursor cursor = textEdit->textCursor();
    //copy_of_text_format = cursor.blockFormat();
    cursor.blockFormat()=copy_of_text_format;
    cursor.mergeBlockFormat(copy_of_text_format);
    textEdit->setTextCursor(cursor);
}


void MainWindow::left_alignment_slot()
{
    QTextCursor cursor = textEdit->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignLeft);
    cursor.mergeBlockFormat(textBlockFormat);
    textEdit->setTextCursor(cursor);
}

void MainWindow::right_alignment_slot()
{
    QTextCursor cursor = textEdit->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignRight);
    cursor.mergeBlockFormat(textBlockFormat);
    textEdit->setTextCursor(cursor);
}

void MainWindow::center_alignment_slot()
{
    QTextCursor cursor = textEdit->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignCenter);
    cursor.mergeBlockFormat(textBlockFormat);
    textEdit->setTextCursor(cursor);
}

void MainWindow::set_fond()
{

    QFont font = textEdit->textCursor().charFormat().font();
    QFontDialog fntDlg(font,this);
    bool b[]={true};
    font = fntDlg.getFont(b);
    if(b[0]){
        QTextCharFormat fmt = textEdit->textCursor().charFormat();
        fmt.setFont(font);
        fmt.setForeground(QBrush(QColor(0,0,0)));
        textEdit->textCursor().setCharFormat(fmt);
    }
}



void MainWindow::titles_of_menuBar()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    formatting = menuBar()->addMenu(tr("&Format"));
    aboutQt = menuBar()->addMenu(tr("&AboutQt"));
}
