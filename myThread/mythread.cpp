#include "mythread.h"
#include <QDebug>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    stopped=false;
}

void MyThread::stop()
{
    stopped=true;
}

void MyThread::run()
{
    qreal i=0;
    if(!stopped){
        qDebug()<< QString("in MyThread: %1").arg(i++);
        stopped=false;
    }
}
