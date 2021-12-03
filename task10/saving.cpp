#include "saving.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QQmlApplicationEngine>

Saving::Saving(QObject *parent)
    : QObject(parent)
   // , m_name("Wha")
{
    QFile file("output.txt");
    if (file.open(QIODevice::ReadOnly))
    while(!file.atEnd()) {
        list.append(file.readLine());
        tasks++;
    }
}

void Saving::saveData(QString name, QString date, int progress) {


    list.insert(tasks, name + ", " + date + ", " + QString::number(progress) + "\n");
    writeToFile();
    tasks++;
}

//QString Saving::_name()
//{
//    return  m_name;
//}

//QString Saving::_date()
//{
//    return  m_date;
//}

//void Saving::setName(QString newName)
//{
//     if(newName==nullptr)
//        emit nameChanged();
//}

void Saving::writeToFile() {
    QFile file("output.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        for (int i = 0; i < list.count(); i++) {
            stream << list.at(i).toUtf8();
        }
        file.flush();
        file.close();
    }

}
