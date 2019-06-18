#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])//主程序入口
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
