#pragma once

#include <QMainWindow>



#include <QTextEdit>
#include <QMenuBar>
#include <QToolBar>
#include <QMenu>
#include <QMdiSubWindow>
#include <QMdiArea>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void About_to_Q();
private slots:
    void add_sub_win();

    void new_file();
    void open();
    void save();
    void saveAs();
    void about_to_exit();
    void printer();

    void copy_slot();
    void past_slot();
    void cut_slot();

    void copy_format_slot();
    void paste_format_slot();
    void left_alignment_slot();
    void right_alignment_slot();
    void center_alignment_slot();
    void paste_curr_time();

    void set_fond();

private:
    void titles_of_menuBar();
    void createActions();
    void createMenus();
    void createToolBars();
    void set_Actions_disabled();
    void set_Actions_disabled_false();

private:
    Ui::MainWindow *ui;

    QMdiSubWindow *subWindow;
    QMdiArea *mdiArea;
    //QTextEdit *curEdit;
    QString curFile;
    QDateTime *today;

    //titles of menuBar
    QTextBlockFormat copy_of_text_format;
    QString buff_txt;


    //QTextEdit *textEdit;
    QMenu *fileMenu;
    QMenu *formatting;
    QMenu *aboutQt;

    QToolBar *fileToolBar;
//    QToolBar *editToolBar;
//    QActionGroup *windowActionGroup;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *printerAciton;


    QAction *copy_A;
    QAction *paste_A;
    QAction *cut_A;
    QAction *copy_format_A;
    QAction *paste_format_A;
    QAction *left_alignment_A;
    QAction *right_alignment_A;
    QAction *center_alignment_A;
    QAction *paste_curr_time_A;

    QAction *set_font_A;

    QAction *aboutAction;

};
