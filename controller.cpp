#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    _dataProvider=new DataProvider(this);
    _dateTimeProvider=new CurrentDateAndTimeProvider(this);
}

QString Controller::status() const
{
    return _status;
}
