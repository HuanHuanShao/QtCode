#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = nullptr);

signals:
    void isDone();
public slots:
    void stopThread();

protected:
    virtual void run();

signals:

public slots:
};

#endif // MYTHREAD_H
