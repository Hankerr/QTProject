#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTextCodec>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //解决乱码的问题
    //    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    //    QTextCodec::setCodecForLocale(codec);
    //    db.exec("set NAMES UTF8");

    db.setHostName("localhost");
    db.setDatabaseName("mydata");//数据库
    db.setUserName("root");
    db.setPassword("");
    if(!db.open())
        return false;
    QSqlQuery query(db);
    //query.exec("create table student(id int primary key,name varchar(20))");//建表
    //query.exec("insert into student values (0,'fanggengen')");
    //query.exec("insert into student values (1,'wangwu')");
    //query.exec("insert into student values (2,'zhangsan')");
    //query.exec("commit");
    return true;
}

#endif // CONNECTION_H
