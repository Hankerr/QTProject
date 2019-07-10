#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&myProcess,SIGNAL(readyRead()),this,SLOT(showResult()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //myProcess.start("notepad.exe");
    QString command="cmd.exe";
    QStringList arguments;
    arguments<<"/c dir&pause";
    myProcess.start(command,arguments);
}

void MainWindow::showResult()
{
    qDebug()<<"showResult:"<<endl
           <<QString(QString::fromLocal8Bit(myProcess.readAll()));
}
