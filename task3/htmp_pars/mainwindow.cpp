#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	{
		ui->setupUi(this);
	}

MainWindow::~MainWindow()
	{
		delete ui;
	}

QStringList parse_currency(QString raw_html){
		QStringList result;

            //поиск информации о курсах валют
			qint32 last = 0;
			while (last!=-1) {
				int begin, end;
				last = raw_html.indexOf("rate__currency",last); //поиск по классу блока <div> // <div class="rate__currency svelte-1lhokyh">74.39</div>
				begin = raw_html.indexOf(">",last) + 1;
				end = raw_html.indexOf("<",begin);
				if (begin != -1 && end != -1){
					last = end;
                    QString tmp = raw_html.mid(begin,end-begin);
                    result.append(tmp);
				}

			}

        if (result.length()<2) throw -1; //бросаем исключение при количестве резултатов меньше двух
		return result;
	}

QStringList parse_weather(QString raw_html){
		QStringList result;
        QStringList searching_data = {"weather__city","weather__temp","weather__description","weather__humidity"};

        //поиск информации о курсах валют
		qint32 last = 0;
        foreach (const QString str, searching_data){
			int begin, end;
			last = raw_html.indexOf(str,last);
                if (last == -1) throw -1; //бросаем исключение при отсутсвии данных
			begin = raw_html.indexOf(">",last) + 1;
			end = raw_html.indexOf("<",begin);
			if (begin != -1 && end != -1){
				last = end;
                QString tmp = raw_html.mid(begin,end-begin);
                result.append(tmp);
			}else{
                throw -1; //если не удалось вырезать строку бросаем исключение
			}
		}
		return result;
	}

void MainWindow::on_pushButton_loadHTML_released()
{
		QString filename = QFileDialog::getOpenFileName(this, "Open file", QDir::current().path(), "Webpage, HMTL files (*.html *.htm);;All files(*.*)");
		if (filename.isEmpty()) return;
		QFile HTML_file(filename);
		if(HTML_file.open(QIODevice::ReadOnly)){
			QByteArray bytes = HTML_file.readAll();
			QString HTML_raw = bytes.data();



			try {
				QStringList results = parse_currency(HTML_raw);
				ui->lineEdit_USD->setText(results[0]);
				ui->lineEdit_EUR->setText(results[1]);
			}  catch (int) {
                    ui->lineEdit_USD->setText("Cannot parse this file");
                    ui->lineEdit_EUR->setText("Cannot parse this file");
			}



			try {
				ui->plainTextEdit->clear();
				QStringList weather = parse_weather(HTML_raw);
				ui->plainTextEdit->appendPlainText(weather[0]);
				ui->plainTextEdit->appendPlainText(weather[1]+", "+weather[2]);
				ui->plainTextEdit->appendPlainText(weather[3]);
			}  catch (int) {
                ui->plainTextEdit->appendPlainText(QString("Cannot parse this file"));
			}

		}

}
