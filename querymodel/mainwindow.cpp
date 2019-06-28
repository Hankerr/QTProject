#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>
#include <QModelIndex>
#include <qDebug>
#include "mysqlquerymodel.h"

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
    //    QSqlQueryModel *model=new QSqlQueryModel(this);
    //    model->setQuery("select * from student");
    //    model->setHeaderData(0,Qt::Horizontal,tr("id"));
    //    model->setHeaderData(1,Qt::Horizontal,tr("name"));
    //    QTableView *view=new QTableView;
    //    view->setModel(model);
    //    view->show();

    //    int column=model->columnCount();
    //    int rownum=model->rowCount();
    //    QSqlRecord record=model->record(1);
    //    QModelIndex index=model->index(1,1);
    //    qDebug()<<"column is:"<<column<<endl
    //           <<"rownum is:"<<rownum<<endl
    //          <<"record(1) is:"<<record<<endl
    //         <<"the data of index(1,1) is:"<<index.data()<<endl;

    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select* from student");
    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("name"));
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();

    //创建自己模型的对象
    MySqlQueryModel *myModel = new MySqlQueryModel(this);
    myModel->setQuery("select * from student");
    myModel->setHeaderData(0, Qt::Horizontal, tr("id"));
    myModel->setHeaderData(1, Qt::Horizontal, tr("name"));
    QTableView *view1 = new QTableView;
    view1->setWindowTitle("mySqlQueryModel"); //修改窗口标题
    view1->setModel(myModel);
    view1->show();
}
