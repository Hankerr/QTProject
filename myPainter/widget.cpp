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
//    //����Բ
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
    QFont font("����", 15, QFont::Bold, true);
    //�����»���
    font.setUnderline(true);
    //�����ϻ���
    font.setOverline(true);
    //������ĸ��Сд
    font.setCapitalization(QFont::SmallCaps);
    //�����ַ���ļ��
    font.setLetterSpacing(QFont::AbsoluteSpacing, 10);
    //ʹ������
    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(120, 80, tr("yafeilinux"));
    painter.translate(50, 50);
    painter.rotate(90);
    painter.drawText(0, 0, tr("helloqt"));

}
