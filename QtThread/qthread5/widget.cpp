#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 动态分配空间，不能指定父类
    myThread = new MyThread;
    // 创建子线程
    thread = new QThread(this);
    // 将自定义线程加入到子线程中
    myThread->moveToThread(thread);
//    // 开启子线程, 但并没有开启自定义线程
//    thread->start();
    // 线程处理函数内部不允许操作图形界面

    // connect的第五个参数的作用只有在多线程时才有意义
    // 链接方式：默认、队列、直接
    // 默认的时候，如果是多线程，默认链接使用队列,如果是单线程，默认使用
    // 队列方式：槽函数所在线程和接收者一样
    // 直接方式：槽函数所在线程和发送者一样
    connect(myThread, &MyThread::mySignal, this, &Widget::lcdDisp);
    connect(this, &Widget::buttonSignal, myThread, &MyThread::myTimeOut);
    connect(this, &Widget::destroyed, this, &Widget::dealWidgetClose);
    qDebug() << "Widget Thread ID "  << QThread::currentThreadId();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 开启子线程，但是没有启动线程处理函数
    if( thread->isRunning() == true )
    {
        return;
    }
    thread->start();
    myThread->setFlag(false);

    // 不能直接调用线程处理函数
    // 直接调用会导致线程处理函数和主线程在同一个线程
//    myThread->myTimeOut();

    // 只能通过信号和槽来调用
    emit buttonSignal();
}

void Widget::lcdDisp()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void Widget::on_pushButton_2_clicked()
{
    if(thread->isRunning() == false)
    {
        return;
    }
    myThread->setFlag(true);
    thread->quit();
    thread->wait();
}

void Widget::dealWidgetClose()
{
    if(thread->isRunning() == false)
    {
        return;
    }
    myThread->setFlag(true);
    thread->quit();
    thread->wait();
    delete myThread;
}
