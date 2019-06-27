#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlDriver>

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

void MainWindow::on_pushButton_clicked()
{
    /*
     * QSqlQuery query;
    query.exec("select * from student");
    //exec next
    qDebug()<<"exec next():";
    while(query.next()){
        int rowNum=query.at();
        QSqlRecord rect=query.record();
        int columnNum=rect.count();
        int fieldNo=query.record().indexOf("name");
        int id=query.value(0).toInt();
        QString name=query.value(fieldNo).toString();

        qDebug() << "rowNum is : " << rowNum
                 << " id is : " << id
                 << " name is : " << name
                 << " columnNum is : " << columnNum;
    }
    //定位到第二条记录
    qDebug()<<"exec seek(1)";
    if(query.seek(1)){
        qDebug()<<"rowNum is:"<<query.at()
               <<"id is:"<<query.value(0).toInt()
              <<"name is:"<<query.value(1).toString();
    }
    //定位到结果集的最后一条记录
    qDebug()<<"exec last()";
    if(query.last()){
        qDebug()<<"rowNum is:"<<query.at()
               <<"id is:"<<query.value(0).toInt()
              <<"name is:"<<query.value(1).toString();
    }
    */

    //    qDebug()<<"Test";
    //    QSqlQuery query;
    //    int id=ui->spinBox->value();
    //    query.exec(QString("select name from student where id = %1").arg(id));
    //    QString name =query.value(1).toString();
    //    qDebug()<<"select name is:"<<name;

    //    QSqlQuery query;
    //    query.prepare("insert into student(id,name)""values(:id,:name)");
    //    query.bindValue(0,5);
    //    query.bindValue(2,"fanggengen");
    //    query.exec("select * from student");
    //    query.last();
    //    int id=query.value(0).toInt();
    //    QString name=query.value(1).toString();
    //    qDebug()<<id<<name;

    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec("delete from student");
    query.prepare("insert into student values(?,?)");
    QVariantList ints;
    ints<<11<<12<<13<<14;
    query.addBindValue(ints);
    QVariantList names;
    names<<"zhangsan"<<"wangwu"<<"lisi"<<QVariant(QVariant::String);
    query.addBindValue(names);
    //输出整张表
    query.exec("select * from student");
    while(query.next()){
        int id=query.value(0).toInt();
        QString name=query.value(1).toString();
        qDebug()<<id<<name;
    }
    query.last();
    qDebug()<<query.value(0).toInt()<<query.value(1).toString();
    QSqlDatabase::database().commit();
}








