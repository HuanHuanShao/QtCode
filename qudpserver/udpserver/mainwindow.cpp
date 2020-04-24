#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Server");
    timer1 = new QTimer(this);
    nUdpSocket = new QUdpSocket(this);
    connect(timer1,SIGNAL(timeout()), this, SLOT(timeout()));
    connect(ui->StartUdpButton,SIGNAL(clicked()), this, SLOT(StartOrStopTx()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    QString msg = ui->TxMsgEdit->text();
    if(msg == "")
    {
        qDebug() << "Message is empty!" << endl;
        return;
    }

    qint64 length = 0;
    if( ( length = nUdpSocket->writeDatagram(msg.toLatin1(), \
                                             msg.length(), \
                                             QHostAddress::Broadcast, \
                                             portNum) ) != msg.length() )
    {
        qDebug() << "Length is error!" << endl;
        return;
    }
}

void MainWindow::StartOrStopTx()
{
    if(!isStarted)
    {
        isStarted = true;
        timer1->start(1000);
        ui->StartUdpButton->setText(tr("结束"));
    }
    else
    {
        isStarted = false;
        timer1->stop();
        ui->StartUdpButton->setText(tr("开始"));
    }
}
