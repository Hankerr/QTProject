#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    id1=startTimer(1000);
    id2=startTimer(2000);
    id3=startTimer(5000);
    ui->setupUi(this);

    //关联自定义计时器与槽
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::timerUpdate);
    timer->start(1000);

    //qsrand 随机数
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==id1){
        ui->label->setText(tr("%1").arg(qrand()%10));
    }else if(event->timerId()==id2){
        ui->label_2->setText(tr("%1").arg("Hello Qt"));
    }else if(event->timerId()==id3){
        qApp->quit();
    }
}

void Widget::timerUpdate()
{
    //获取当前系统时间
    QDateTime time=QDateTime::currentDateTime();
    //将时间戳转为字符串
    QString str=time.toString("yyyy-MM-dd HH:mm:ss dddd");
    //标签显示time
    ui->lineEdit->setText(str);
    int rand=qrand()%300;
    ui->lineEdit->move(rand,rand);
}
