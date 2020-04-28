#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QThread>
#include <QDebug>

#include "mythread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    QTimer *timer1;
    mythread *thread;

    void dealTimeOut();

private slots:
    void on_pushButton_clicked();
    void threadDone();

private:
    Ui::Widget *ui;
};



#endif // WIDGET_H
