#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlRelationalDelegate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model=new QSqlRelationalTableModel(this);
    //字段变换时写入数据库
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setTable("student1");
    //设置外键setRelation
    model->setRelation(2,QSqlRelation("course", "id", "name"));
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Course"));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
