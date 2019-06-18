#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("WidgetProject");
    this->resize(500,300);

    lineEdit =new QLineEdit(this);
    lineEdit->setGeometry(30,20,180,36);
    lineEdit->setPlaceholderText("Please Input...");
    btn=new QPushButton("show",this);
    btn->setGeometry(220,20,250,36);

    label=new QLabel(this);
    label->setGeometry(30,70,250,30);

    QObject::connect(btn,SIGNAL(clicked()),this,SLOT(showText()));
}

void MainWindow::showText(){
    label->setText(lineEdit->text());
}
