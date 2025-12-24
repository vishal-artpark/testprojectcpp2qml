#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include"currentdateandtimeprovider.h"
#include"dataprovider.h"

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CurrentDateAndTimeProvider *dateTimeProvider READ dateTimeProvider NOTIFY dateTimeProviderChanged)
    Q_PROPERTY(DataProvider *dataProvider READ dataProvider NOTIFY dataProviderChanged)
    Q_PROPERTY(QString status READ status NOTIFY statusChanged)

public:
    explicit Controller(QObject *parent = nullptr);
    inline CurrentDateAndTimeProvider*dateTimeProvider()const{
        return _dateTimeProvider;
    }
    inline DataProvider*dataProvider()const{
        return _dataProvider;
    }
    QString status() const;

    Q_INVOKABLE void refresh(){
        _status="Ready to Go.";
        emit statusChanged();
    }
private:
    CurrentDateAndTimeProvider*_dateTimeProvider;
    DataProvider*_dataProvider;
    QString _status{"Not Ready"};

signals:
    void dateTimeProviderChanged();
    void dataProviderChanged();
    void statusChanged();
};

#endif // CONTROLLER_H
