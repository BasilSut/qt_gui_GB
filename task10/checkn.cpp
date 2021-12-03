#include "checkn.h"

CheckN::CheckN(QObject *parent)
    : QObject(parent)
    , m_name("Check")
{

}

QString CheckN::_name() const
{
    return m_name;
}

QString CheckN::check(QString)
{

}

void CheckN::setName(QString)
{
   // if()
}
