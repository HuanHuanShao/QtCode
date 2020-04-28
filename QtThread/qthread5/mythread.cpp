#include "mythread.h"

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}

void MyThread::myTimeOut()
{
    while(!isStop)
    {
        QThread::sleep(1);
        emit mySignal();
        qDebug() << "MyThread Thread ID " << QThread::currentThreadId();
    }


}

void MyThread::setFlag(bool flag)
{
    isStop = flag;
}
