#include <QCoreApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //打开sql
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydata");
    db.setUserName("root");
    db.setPassword("");
    if(!db.open()){
        qDebug()<<"Open Mysql Faile"<<endl;//1.换行，2。刷新流
    }else{
        qDebug()<<"Open Mysql success"<<endl;
    }

    QSqlQuery query(db);

    //varchar指定长度20，不然会出错
    query.exec("create table student(id int primary key,name varchar(20))");

    query.exec("insert into student values(1,'fanggengen')");
    query.exec("insert into student values(2,'gengen')");
    query.exec("insert into student values(3,'fang')");
    query.exec("insert into student values(4,'gen')");

    query.exec("select "
               "id,name from student "
               "where id >= 2");

    while(query.next()){
        int stdId=query.value(0).toInt();
        QString stdName=query.value(1).toString();
        qDebug()<<stdId<<stdName;
    }

    return a.exec();
}







