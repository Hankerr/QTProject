#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

//登录
void LoginDialog::on_login_pushBtn_clicked()
{
    qDebug()<<"loginTest"<<endl;
}

//取消登录
void LoginDialog::on_logincancle_pushButton_clicked()
{
    ui->Username_lineEdit->clear();
    ui->Password_lineEdit->clear();
}
