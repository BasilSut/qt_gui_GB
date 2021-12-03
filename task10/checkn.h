#pragma once

#include <QObject>

class CheckN : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString _name WRITE _name READ setName NOTIFY nameChanged);
public:
    explicit CheckN(QObject *parent = nullptr);



     QString _name() const;
     Q_INVOKABLE QString check(QString);
 signals:
     void nameChanged();
     //void dateChanged();
     //void numoftasksChanged();

 public slots:
     void setName(QString);
     //void setDate(QString);
     //void setnumofTasks(QString);
 private:

     QString m_name;
};


