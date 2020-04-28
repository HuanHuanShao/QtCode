#include "mythread.h"

mythread::mythread(QObject *parent) : QThread(parent)
{
    qDebug() << "mythread Thread ID "  << currentThreadId();
}

void mythread::run()
{
    sleep(5);

    emit isDone();
}

void mythread::stopThread()
{
    qDebug() << "Quit Thread";
    quit();
    wait();
}
