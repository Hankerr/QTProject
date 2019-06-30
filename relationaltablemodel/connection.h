#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
   QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
   db.setDatabaseName("mydata");
   db.setHostName("localhost");
   db.setUserName("root");
   db.setPassword("");
   if(!db.open()) return false;
   QSqlQuery query(db);
   query.exec("create table student1 (id int primary key, name varchar(20),course int)");
   query.exec("insert into student1 values(1,'yafei0',1)");
   query.exec("insert into student1 values(2,'yafei1',1)");
   query.exec("insert into student1 values(3,'yafei2',2)");

   query.exec("create table course (id int primary key, name varchar(20), teacher varchar(20))");
   query.exec("insert into course values(1,'Math','yafeilinux1')");
   query.exec("insert into course values(2,'English','yafeilinux2')");
   query.exec("insert into course values(3,'Computer','yafeilinux3')");
   query.exec("commit");
   return true;
}
#endif // CONNECTION_H
