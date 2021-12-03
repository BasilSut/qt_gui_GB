#pragma once
#include <QObject>
#include <QStringList>
#include <QArrayData>

class Saving : public QObject {
    Q_OBJECT

public:
    explicit Saving(QObject *parent = nullptr);

    Q_INVOKABLE void saveData(QString name, QString date, int progress);
    //Q_PROPERTY(int tasks WRITE tasks READ tasks NOTIFY numoftasksChanged)
    //Q_PROPERTY(QString _name WRITE _name READ _name NOTIFY nameChanged)
    //Q_PROPERTY(QString _date WRITE  _date READ _date NOTIFY dateChanged)

   // QString _name();
    //QString _date();
signals:
    //void nameChanged();
    //void dateChanged();
    //void numoftasksChanged();

public slots:
    //void setName(QString);
    //void setDate(QString);
    //void setnumofTasks(QString);
private:
    QStringList list;
    void writeToFile();
    int tasks = 0;
    //QString m_name, m_date;


};

