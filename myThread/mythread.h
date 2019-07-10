#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QThread *parent = nullptr);
    void stop();
signals:

public slots:
protected:
    void run();
private:
    volatile bool stopped;
};

#endif // MYTHREAD_H
