#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    //主机名
//    QString localHostName=QHostInfo::localHostName();
//    qDebug()<<"localHostName:"<<localHostName;
//    //IP 地址
//    qDebug()<<QString::fromLocal8Bit("所有IP地址:");
//    QHostInfo info=QHostInfo::fromName(localHostName);
//    for(int i=0;i<info.addresses().count();i++){
//        qDebug()<<"IP Address:"<<info.addresses().at(i);
//    }

//    //IPv4地址
//    foreach(QHostAddress address,info.addresses()){
//        if(address.protocol()==QAbstractSocket::IPv4Protocol){
//            qDebug()<<QString::fromLocal8Bit("IPv4地址:")<<address.toString();
//        }
//    }

//    QHostInfo::lookupHost("www.baidu.com",this,SLOT(lookUp(QHostInfo)));
}

Widget::~Widget()
{
    delete ui;
}

//void Widget::lookUp(const QHostInfo &host)
//{
//    qDebug()<<host.addresses().first().toString();
//}
