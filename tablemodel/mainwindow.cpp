#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model=new QSqlTableModel(this);
    model->setTable("student");
    //模型的保存策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    //删除第二列
    //model->removeColumn(1);
    ui->tableView->setModel(model);
    //似的tablename不可以被编辑
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //codec = QTextCodec::codecForName("UTF-8");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    QString name=ui->lineEdit->text();
    model->setFilter(QString("name='%1'").arg(name));
    model->select();
}

//提交修改
void MainWindow::on_pushButton_clicked()
{
    model->database().transaction();//开始事物操作
    if(model->submitAll()){
        model->database().commit();//提交
    }else{
        model->database().rollback();
        QMessageBox::warning(this,tr("QTableModel"),tr("sql fail:%1").arg(model->lastError().text()));
    }
}
//撤回修改
void MainWindow::on_pushButton_2_clicked()
{
    model->revertAll();
}

void MainWindow::on_pushButton_6_clicked()
{
    model->setTable("student1");
    model->select();
}

void MainWindow::on_pushButton_7_clicked()
{
    model->setSort(1,Qt::AscendingOrder);
    model->select();
}

void MainWindow::on_toolButton_clicked()
{
    model->setSort(1,Qt::DescendingOrder);
    model->select();
}

void MainWindow::on_pushButton_4_clicked()
{
    //获取选择行
    int curRow=ui->tableView->currentIndex().row();
    //删除该行
    model->removeColumn(curRow);
    int queryOk = QMessageBox::warning(this,tr("Query commit"),
                                       tr("Are You Sure Delete"),
                                       QMessageBox::Yes | QMessageBox::No);
    if(queryOk==QMessageBox::No){
        model->revertAll();
    } else
        model->submitAll();
}

//添加一行记录
void MainWindow::on_pushButton_3_clicked()
{
    int rowNum=model->rowCount();
    int id=11;
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),id);
    model->submitAll();
}
