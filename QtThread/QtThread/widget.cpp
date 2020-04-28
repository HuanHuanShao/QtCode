#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Widget thread ID " << QThread::currentThreadId();

    timer1 = new QTimer(this);
    thread = new mythread(this);
    connect(timer1, &QTimer::timeout, this, &Widget::dealTimeOut);
    connect(thread, &QThread::finished, this, &Widget::threadDone);
    connect(this, &Widget::destroyed, thread, &mythread::stopThread);
}

void Widget::dealTimeOut()
{
    static int i = 0;
    i++;

    ui->lcdNumber->display(i);
}

void Widget::threadDone()
{
    timer1->stop();
    qDebug() << "timer finished!";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 如果定时器没有工作
    if(timer1->isActive() == false)
    {
        timer1->start(100);
    }

    thread->start();
}
