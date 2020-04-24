#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Client");

    nUdpSocket = new QUdpSocket(this);

    connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(nUdpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));

    bool result = nUdpSocket->bind(portNum, QUdpSocket::ShareAddress);    // 绑定端口号
    if(!result)
    {
        QMessageBox::information(this, tr("error"), tr("udp socket creat error!"));

        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dataReceived()
{
    qDebug() << "UDP has a socket!" << endl;
    while(nUdpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;

        datagram.resize(nUdpSocket->pendingDatagramSize());

        nUdpSocket->readDatagram(datagram.data(), datagram.size());

        QString msg = datagram.data();
        ui->RxMsgEdit->insertPlainText(msg);
    }
}

