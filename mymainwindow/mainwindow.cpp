#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*QAction *openAction=new QAction(tr("&Open"),this);
    QIcon icon(":/myimages/images/2.png");
    openAction->setIcon(icon);
    openAction->setShortcut(QKeySequence("Ctrl+0"));
    ui->menu_F->addAction(openAction);

    QMenu *Menu_E=ui->menuBar->addMenu(QString::fromUtf8("Edit&E"));
    QAction *findAction=new QAction(tr("&Find"),this);
    QIcon icon1(":/myimages/images/3.png");
    findAction->setIcon(icon1);
    findAction->setShortcut(QKeySequence(tr("Ctrl+F")));
    Menu_E->addAction(findAction);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
