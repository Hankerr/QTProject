#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>

class QMouseEvent;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;
private:
    qreal scale;
    QPushButton *button;
private slots:
    void zoomIn();
private:
    QPixmap tmpPix;
    bool isDrawing;
};

#endif // DIALOG_H
