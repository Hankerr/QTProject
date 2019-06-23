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

void Dialog::mypaint(QPainter *)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load("../mypixmap/Other files/2.png");
    painter.drawPixmap(10,10,20,20,pixmap);
}
