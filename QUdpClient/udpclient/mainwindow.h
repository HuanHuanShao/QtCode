#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QMessageBox>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *timer1;
    QUdpSocket *nUdpSocket;

    quint16 portNum = 5555;

public slots:
    void dataReceived();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
