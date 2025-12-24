#include "currentdateandtimeprovider.h"

#include <QTimer>

CurrentDateAndTimeProvider::CurrentDateAndTimeProvider(QObject *parent)
    : QObject{parent}
{
    _timer=new QTimer(this);
    connect(_timer,&QTimer::timeout,this,&CurrentDateAndTimeProvider::updateTime);
}

QString CurrentDateAndTimeProvider::time() const
{
    return _time;
}

QString CurrentDateAndTimeProvider::date() const
{
    return _date;
}

void CurrentDateAndTimeProvider::updateTime()
{
    _time=QDateTime::currentDateTime().time().toString();
    emit timeChanged();
    _timer->start(1000);
}
