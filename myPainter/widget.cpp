#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);
//    painter.drawLine(QPointF(0,0),QPointF(100,100));
//    //绘制圆
//    QRectF rectangle(10.0, 20.0, 80.0, 60.0);

//    //QPainter painter(this);
//    painter.drawEllipse(rectangle);

//    QPen pen;
//    pen.setColor(QColor(255,0,0));
//    QBrush brush(QColor(0,255,0,125));
//    painter.setPen(pen);
//    painter.setBrush(brush);
//    painter.drawRect(60,60,200,100);

//    QPainter painter(this);
//    QPen pen(Qt::DotLine);
//    QBrush brush(Qt::blue);
//    brush.setStyle(Qt::DiagCrossPattern);
//    painter.setPen(pen);
//    painter.setBrush(brush);
//    painter.drawRect(50,50,200,200);

//    QPainter painter(this);
//    painter.drawText(100,100,"Hello Qt");

    QPainter painter(this);
    QFont font("宋体", 15, QFont::Bold, true);
    //设置下划线
    font.setUnderline(true);
    //设置上划线
    font.setOverline(true);
    //设置字母大小写
    font.setCapitalization(QFont::SmallCaps);
    //设置字符间的间距
    font.setLetterSpacing(QFont::AbsoluteSpacing, 10);
    //使用字体
    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(120, 80, tr("yafeilinux"));
    painter.translate(50, 50);
    painter.rotate(90);
    painter.drawText(0, 0, tr("helloqt"));

}
