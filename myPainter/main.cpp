#include "dialog.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydata");
    db.setUserName("root");
    db.setPassword("");
    if(!db.open()){
        qDebug() << "connect MySql fail"<<endl;//endl 1,换行2,刷新输出流,提高程序效率
    }else{
        qDebug() << "connect Mysql success"<<endl;
    }
    return a.exec();
}
