#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *timer1;
    QUdpSocket *nUdpSocket;

    bool isStarted = false;
    quint16 portNum = 5555;
    int16_t tt = 0;

public slots:
    void StartOrStopTx();
    void timeout();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
