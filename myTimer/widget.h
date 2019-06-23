#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimerEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
protected:
    void timerEvent(QTimerEvent *);
private:
    int id1,id2,id3;
private:
    void timerUpdate();
};

#endif // WIDGET_H
