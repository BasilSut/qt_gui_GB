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
#include<QPrinter>
#include <QPrintDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Text Editor"));
    titles_of_menuBar();
    createActions();
    createMenus();
    createToolBars();
    today = new QDateTime();

    //textEdit = new QTextEdit(this); однодокументный вариант
    //setCentralWidget(textEdit);
    //многодокументный:
    mdiArea = new QMdiArea(this);
    setCentralWidget(mdiArea);
    //mdiArea->setViewMode(QMdiArea::TabbedView);
//    subWindow = new QMdiSubWindow(mdiArea);
//    subWindow->setWidget( new QTextEdit( subWindow ) );
//    mdiArea->addSubWindow( subWindow );
    set_Actions_disabled();
    connect(newAction, SIGNAL(triggered()), this, SLOT(add_subwin()));


    //add_sub_win();


}

MainWindow::~MainWindow()
{
    delete today;
    delete ui;
}


void MainWindow::add_sub_win(){
    set_Actions_disabled_false();
    subWindow = new QMdiSubWindow( mdiArea );
    subWindow->setWidget( new QTextEdit( subWindow ) );
    subWindow->setAttribute( Qt::WA_DeleteOnClose );
    mdiArea->addSubWindow( subWindow );
    mdiArea->activateNextSubWindow();
    subWindow->show();

}

void MainWindow::createActions(){

    newAction = new QAction(tr("&New"));
    newAction->setIcon(QIcon(":/png/icons/newf.png"));
    connect(newAction,SIGNAL(triggered()),this,SLOT(new_file()));

    openAction = new QAction(tr("&Open"));
    openAction->setIcon(QIcon(":/png/icons/openf.png"));
    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));

    saveAction = new QAction(tr("&Save"));
    saveAction->setIcon(QIcon(":/png/icons/savef.png"));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));

    saveAsAction = new QAction(tr("&Save &As..."));
    saveAsAction->setIcon(QIcon(":/png/icons/savefAS.png"));
    connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveAs()));

    exitAction = new QAction(tr("&Exit"));
    exitAction->setIcon(QIcon(":/png/icons/exit.png"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(about_to_exit()));

    printerAciton = new QAction(tr("&Print"));
    printerAciton->setIcon(QIcon(":/png/icons/printer.png"));
    connect(printerAciton,SIGNAL(triggered()),this,SLOT(printer()));
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
    paste_curr_time_A = new QAction(tr("&Paste current time"));
    paste_curr_time_A->setIcon(QIcon(":/png/icons/today.png"));
    connect(paste_curr_time_A,SIGNAL(triggered()),this,SLOT(paste_curr_time()));

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
    fileMenu->addAction(printerAciton);

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
    formatting->addAction(paste_curr_time_A);

}

void MainWindow::createToolBars(){
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);
    fileToolBar->addAction(printerAciton);
    fileToolBar->addAction(paste_curr_time_A);
}

void MainWindow::new_file()
{
    static int documentNumber = 1;
    curFile = tr("document%1.txt").arg(documentNumber);
    add_sub_win();
    mdiArea->activeSubWindow()->setWindowTitle(curFile);
    //((QTextEdit*)mdiArea->activeSubWindow()->widget())->setText("Hello");


    //setWindowTitle(curFile + "[*]");

    ++documentNumber;
}

void MainWindow::open(){
    QString filter = "ALL File (*.*) ;; Text File(*.txt) ;; CPP File (*.cpp) ;; HPP File (*.h)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file", QDir::currentPath(),filter);
    //QString file_name = QFileDialog::getOpenFileName(this,"Open a file");
    add_sub_win();
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
    mdiArea->activeSubWindow()->setWindowTitle(fi.baseName());
    ((QTextEdit*)mdiArea->activeSubWindow()->widget())->setText(txt);

    //textEdit->append();
    file.close();
}


void MainWindow::save(){



        saveAs();


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

    //output_data<<textEdit->toPlainText();
    output_data << ((QTextEdit*)mdiArea->activeSubWindow()->widget())->toPlainText();
    file.close();
}

void MainWindow::about_to_exit()
{
    emit About_to_Q();
}

void MainWindow::printer()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle("Print");
    if (dlg.exec() != QDialog::Accepted)
        return;
}

void MainWindow::copy_slot()
{
    //buff_txt = textEdit->textCursor().selectedText();
    buff_txt = ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor().selectedText();
    qApp->clipboard()->setText(buff_txt);
}

void MainWindow::past_slot()
{
    //textEdit->textCursor().insertText(qApp->clipboard()->text());
    ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor().insertText(qApp->clipboard()->text());
}

void MainWindow::cut_slot()
{
    //buff_txt = textEdit->textCursor().selectedText();
    ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor().selectedText();
    qApp->clipboard()->setText(buff_txt);
    //textEdit->textCursor().removeSelectedText();
    ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor().removeSelectedText();
}

void MainWindow::copy_format_slot()
{
    //QTextCursor cursor = textEdit->textCursor();
    QTextCursor cursor = ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor();
    copy_of_text_format = cursor.blockFormat();
}

void MainWindow::paste_format_slot()
{
    //QTextCursor cursor = textEdit->textCursor();
    //copy_of_text_format = cursor.blockFormat();
    QTextCursor cursor =((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor();
    cursor.blockFormat()=copy_of_text_format;
    cursor.mergeBlockFormat(copy_of_text_format);
    //textEdit->setTextCursor(cursor);
    ((QTextEdit*)mdiArea->activeSubWindow()->widget())->setTextCursor(cursor);
}


void MainWindow::left_alignment_slot()
{
    //QTextCursor cursor = textEdit->textCursor();
    QTextCursor cursor = ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignLeft);
    cursor.mergeBlockFormat(textBlockFormat);
    //textEdit->setTextCursor(cursor);
    ((QTextEdit*)mdiArea->activeSubWindow()->widget())->setTextCursor(cursor);
}

void MainWindow::right_alignment_slot()
{
    QTextCursor cursor = ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignRight);
    cursor.mergeBlockFormat(textBlockFormat);
    ((QTextEdit*)mdiArea->activeSubWindow()->widget())->setTextCursor(cursor);
}

void MainWindow::center_alignment_slot()
{
    QTextCursor cursor = ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignCenter);
    cursor.mergeBlockFormat(textBlockFormat);
    ((QTextEdit*)mdiArea->activeSubWindow()->widget())->setTextCursor(cursor);
}

void MainWindow::set_fond()
{

    //QFont font = textEdit->textCursor().charFormat().font();
    QFont font = ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor().charFormat().font();
    QFontDialog fntDlg(font,this);
    bool b[]={true};
    font = fntDlg.getFont(b);
    if(b[0]){
        //QTextCharFormat fmt = textEdit->textCursor().charFormat();
        QTextCharFormat fmt = ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor().charFormat();
        fmt.setFont(font);
        fmt.setForeground(QBrush(QColor(0,0,0)));
        ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor().setCharFormat(fmt);
    }
}

void MainWindow::paste_curr_time(){
    *today = QDateTime::currentDateTime();
    //QTextCursor cursor = ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor();
    ((QTextEdit*)mdiArea->activeSubWindow()->widget())->textCursor().insertText(today->toString("hh:mm:ss ddd d MMMM yyyy"));

}


void MainWindow::titles_of_menuBar()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    formatting = menuBar()->addMenu(tr("&Format"));
    aboutQt = menuBar()->addMenu(tr("&AboutQt"));
}


void MainWindow::set_Actions_disabled()
{
    saveAction->setDisabled(true);
    saveAsAction->setDisabled(true);


     printerAciton->setDisabled(true);


     copy_A->setDisabled(true);
     paste_A->setDisabled(true);
     cut_A->setDisabled(true);
     copy_format_A->setDisabled(true);
     paste_format_A->setDisabled(true);
     left_alignment_A->setDisabled(true);
     right_alignment_A->setDisabled(true);
     center_alignment_A->setDisabled(true);
     paste_curr_time_A->setDisabled(true);

}

void MainWindow::set_Actions_disabled_false()
{
    saveAction->setDisabled(false);
    saveAsAction->setDisabled(false);


     printerAciton->setDisabled(false);


     copy_A->setDisabled(false);
     paste_A->setDisabled(false);
     cut_A->setDisabled(false);
     copy_format_A->setDisabled(false);
     paste_format_A->setDisabled(false);
     left_alignment_A->setDisabled(false);
     right_alignment_A->setDisabled(false);
     center_alignment_A->setDisabled(false);
     paste_curr_time_A->setDisabled(false);
}
