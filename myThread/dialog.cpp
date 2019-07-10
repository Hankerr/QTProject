#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_startButton_clicked()
{
    thread.start();
    ui->startButton->setEnabled(false);
    ui->EndButton->setEnabled(true);
}

void Dialog::on_EndButton_clicked()
{
    if(thread.isRunning()){
        thread.stop();
        ui->startButton->setEnabled(true);
        ui->startButton->setEnabled(false);
    }
}
