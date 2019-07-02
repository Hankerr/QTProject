#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private:
    QNetworkAccessManager *manager;
private slots:
    void on_pushButton_clicked();
    void httpFinished();
    void httpReadyRead();  //接收到数据时的处理
    void updateDataReadProgress(qint64,qint64);
public:
    void startRequest(QUrl url);
private:
    QUrl url;
    QNetworkReply *reply;
    QFile *file;
};

#endif // MAINWINDOW_H
