#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    resize(700,400);
    pix=QPixmap(500,300);
    pix.fill(Qt::white);

    //×Ô¶¨Òå²Û
    scale=1;
    button =new QPushButton(this);
    button->setText(tr("zoomIn"));
    button->move(500,350);
    connect(button,&QPushButton::clicked,this,&Dialog::zoomIn);

    isDrawing=false;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *)
{
    //    if(scale!=1){
    //        QPixmap copyPix(pix.size()*scale);
    //        QPainter pter(&copyPix);
    //        pter.scale(scale,scale);
    //        pter.drawPixmap(0,0,pix);
    //        pix=copyPix;
    //        scale=1;
    //    }
    //    QPainter pp(&pix);

    //    pp.scale(scale,scale);

    //    pp.drawLine(lastPoint,endPoint);
    //    lastPoint=endPoint;
    //    QPainter painter(this);

    //    //painter.scale(scale,scale);

    //    painter.drawPixmap(0,0,pix);

    //    int x,y,w,h;
    //    x=lastPoint.x();
    //    y=lastPoint.y();
    //    w=endPoint.x()-x;
    //    h=endPoint.y()-y;
    //    QPainter pp(&pix);
    //    pp.drawRect(x,y,w,h);
    //    QPainter painter(this);
    //    painter.drawPixmap(10,10,pix);

    int x,y,w,h;
    x=lastPoint.x();
    y=lastPoint.y();
    w=endPoint.x()-x;
    h=endPoint.y()-y;
    QPainter painter(this);
    QPixmap tmppix;
    if(isDrawing){
        tmppix=pix;
        QPainter pp(&tmppix);
        pp.drawRect(x,y,w,h);
        painter.drawPixmap(0,0,tmppix);
    }else{
        QPainter pp(&pix);
        pp.drawRect(x,y,w,h);
        painter.drawPixmap(0,0,pix);
    }
}

void Dialog::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton){
        lastPoint=e->pos();
        isDrawing=true;
    }
    endPoint=lastPoint;
}

void Dialog::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons()&Qt::LeftButton){
        endPoint=e->pos();
        update();
    }
}

void Dialog::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton){
        endPoint=e->pos();
        isDrawing=false;
        update();
    }
}

void Dialog::zoomIn()
{
    //QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    scale *=2;
    update();
}
