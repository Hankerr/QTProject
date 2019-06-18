#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

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

void LoginDialog::on_loginBtn_clicked()
{
    //accept();
    if((ui->usrlineEdit->text().trimmed()==tr("fanggengen"))&&
            (ui->pwdlineEdit->text().trimmed()==tr("123456"))){
        accept();
    }else{
        // warning(QWidget *parent, const QString &title,const QString& text,StandardButton button0, StandardButton button1)
        QMessageBox::warning(this,
                             QString::fromUtf8("Warning!"),
                             QString::fromUtf8("Usr Or Pwd Fault"),
                             QMessageBox::Yes,QMessageBox::No);
        ui->usrlineEdit->clear();
        ui->pwdlineEdit->clear();
        ui->usrlineEdit->setFocus();
    }
}
