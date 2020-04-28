#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

    void myTimeOut();
    void setFlag(bool flag = true);

signals:
    void mySignal();
private:
    bool isStop;

public slots:
};

#endif // MYTHREAD_H
