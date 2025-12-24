#ifndef CURRENTDATEANDTIMEPROVIDER_H
#define CURRENTDATEANDTIMEPROVIDER_H

#include <QObject>
#include<QDebug>
#include <qdatetime.h>
#include <qtimer.h>


class CurrentDateAndTimeProvider : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString date READ date NOTIFY dateChanged)
    Q_PROPERTY(QString time READ time NOTIFY timeChanged)

public:
    explicit CurrentDateAndTimeProvider(QObject *parent = nullptr);
    Q_INVOKABLE void callMe(){
        if(_timer->isActive())return;
        _timer->start(1000);
        _date=QDateTime::currentDateTime().date().toString();
        emit dateChanged();
    };
    QString time() const;

    QString date() const;

signals:
    void timeChanged();
    void dateChanged();

private:
    QString _time{"NA"};
    QString _date{"NA"};
    QTimer*_timer{};
private:
    void updateTime();
};

#endif // CURRENTDATEANDTIMEPROVIDER_H
