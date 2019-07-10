#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    progress = 0;
    view = new QWebEngineView(this);
    setCentralWidget(view);
    resize(800, 600);

    // 关联信号和槽
    connect(view, SIGNAL(loadProgress(int)), this, SLOT(setProgress(int)));
    connect(view, SIGNAL(titleChanged(QString)), this, SLOT(adjustTitle()));
    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(finishLoading(bool)));
    locationEdit = new QLineEdit(this);
    connect(locationEdit, SIGNAL(returnPressed()), this, SLOT(changeLocation()));

    // 向工具栏添加动作和部件
    ui->mainToolBar->addAction(view->pageAction(QWebEnginePage::Back));
    ui->mainToolBar->addAction(view->pageAction(QWebEnginePage::Forward));
    ui->mainToolBar->addAction(view->pageAction(QWebEnginePage::Reload));
    ui->mainToolBar->addAction(view->pageAction(QWebEnginePage::Stop));
    ui->mainToolBar->addWidget(locationEdit);

    // 设置并加载初始网页地址
    locationEdit->setText("http://www.baidu.com");
    view->load(QUrl("http://www.baidu.com"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeLocation()
{
    QUrl url = QUrl(locationEdit->text());
    view->load(url);
    view->setFocus();
}
void MainWindow::setProgress(int p)
{
    progress = p;
    adjustTitle();
}
void MainWindow::adjustTitle()
{
    if ( progress <= 0 || progress >= 100) {
        setWindowTitle(view->title());
    } else {
        setWindowTitle(QString("%1 (%2%)").arg(view->title()).arg(progress));
    }
}
void MainWindow::finishLoading(bool finished)
{
    if (finished) {
        progress = 100;
        setWindowTitle(view->title());
    } else {
        setWindowTitle("web page loading error!");
    }
}
