#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_openConsole_clicked();

    void on_btn_Send_clicked();

    void on_btn_clearSend_clicked();

    void on_btn_clearRecv_clicked();

    void readData();
public:
    char ConvertHexChar(char c);

    void setground();

    void QStringtoHex(QByteArray& sendData,QString str);
private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QPalette palette;
};
#endif // MAINWINDOW_H
