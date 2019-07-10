#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_TranslateButton_clicked()
{
    QString hexString=(ui->hexLineEdit->text()).trimmed().toLower();
    qDebug()<<hexString;
    qlonglong timelong= hexString.toULongLong();
    qDebug()<<timelong;
    ui->decLineEdit->setText("11");
}
