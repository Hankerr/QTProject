#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection(){
    QSqlDatabase db=QSqlDatabase::addDatabase("MYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydata");
    db.setUserName("root");
    db.setPassword("");
    if(!db.open()){
        QMessageBox::critical(0,qApp->tr("Cannot Open Database"),
                              qApp->tr("Unable to establish a database connection."),
                              QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;
    query.exec("drop table if exits student");
    query.exec("create table student "
               "(id int primary key,name varchar(20))");
    query.exec("insert into student values(1,'fanggengen')");
    query.exec("insert into student values(2,'liubinqiang')");
    query.exec("insert into student values(3,'zhangleitao')");
    query.exec("insert into student values(4,'zhangbiao')");

    return true;
}

#endif // CONNECTION_H
