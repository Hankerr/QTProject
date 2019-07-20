#include "qwdialogpen.h"
#include "ui_qwdialogpen.h"
#include <QDebug>

qwdialogpen::qwdialogpen(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::qwdialogpen)
{
    ui->setupUi(this);
}

qwdialogpen::~qwdialogpen()
{
    delete ui;
}

void qwdialogpen::on_pushButton_clicked()
{
    qDebug()<<"Hello Staitc Dll"<<endl;
}
