#ifndef QWDIALOGPEN_H
#define QWDIALOGPEN_H

#include <QFrame>

namespace Ui {
class qwdialogpen;
}

class qwdialogpen : public QFrame
{
    Q_OBJECT

public:
    explicit qwdialogpen(QWidget *parent = 0);
    ~qwdialogpen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::qwdialogpen *ui;
};

#endif // QWDIALOGPEN_H
