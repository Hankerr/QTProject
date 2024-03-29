﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDialog>
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QLineEdit>
#include <QLabel>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化变量未保存
    isUntitled=true;
    //初始化文件为未命名文件
    curFile=codec->toUnicode("未命名.txt");
    //初始化窗口标题为文件名
    setWindowTitle(curFile);

    //查找窗口
    findDlg=new QDialog(this);
    findDlg->setWindowTitle(codec->toUnicode("查找"));
    findLineEdit=new QLineEdit(findDlg);
    QPushButton *findDlgBtn=new QPushButton(codec->toUnicode("查找下一个"),findDlg);
    QVBoxLayout *layout=new QVBoxLayout(findDlg);
    layout->addWidget(findLineEdit);
    layout->addWidget(findDlgBtn);
    //自定义按钮的信号槽
    connect(findDlgBtn,&QPushButton::clicked,this,&MainWindow::showFindEdit);

    //临时状态信息
    //ui->statusBar->showMessage(codec->toUnicode("欢迎访问GG记事本!"),5000);

    //临时标签状态栏信息
    statusLabel =new QLabel;
    statusLabel->setMinimumSize(150,20);
    statusLabel->setFrameShape(QFrame::WinPanel);
    statusLabel->setFrameShadow(QFrame::Sunken);
    ui->statusBar->addWidget(statusLabel);
    statusLabel->setText(codec->toUnicode("欢迎访问GG记事本"));

    //永久标签状态信息（最右侧）
    QLabel *permanent=new QLabel;
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setTextFormat(Qt::RichText);
    permanent->setText(tr("<a href=\"http://www.baidu.com\">Baidu.com</a>"));
    permanent->setOpenExternalLinks(true);
    ui->statusBar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    if(maybeSave()){
        isUntitled=true;
        curFile=codec->toUnicode("未命名.txt");
        setWindowTitle(curFile);
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

bool MainWindow::maybeSave()
{
    //文档被更改
    if(ui->textEdit->document()->isModified()){
        //自定义警告对话框
        QMessageBox box;
        box.setWindowTitle(tr("warning"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile+codec->toUnicode("文件未保存,确认保存"));
        QPushButton *yesBtn=box.addButton(tr("Yes(&Y)"),QMessageBox::YesRole);
        box.addButton(tr("No(&N)"),QMessageBox::NoRole);
        //QPushButton *cancleBtn=box.addButton(tr("Cancle"),QMessageBox::RejectRole);
        box.exec();
        if(box.clickedButton()==yesBtn){
            return save();
        }
        //        else if(box.clickedButton()==cancleBtn){
        //            return false;
        //        }
    }
    //文档未更改
    return true;
}

bool MainWindow::save()
{
    if(isUntitled){
        return saveAs();
    }else{
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("saveAs"),curFile);
    if(fileName.isEmpty())
        return false;
    return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,
                             codec->toUnicode("多文档编辑器"),
                             codec->toUnicode("无法读取文件 %1:\n%2")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    //鼠标指针变为等待状态
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    out<<ui->textEdit->toPlainText();
    //鼠标指针恢复原来状态
    QApplication::restoreOverrideCursor();
    isUntitled=false;
    //获取文件的标准路径
    curFile=QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

bool MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,
                             codec->toUnicode("多文档编辑器"),
                             codec->toUnicode("无法读取文件 %1:\n%2")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    //读取文件中的文本
    ui->textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();
    //设置当前文件
    curFile=QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow::on_action_New_triggered()
{
    newFile();
}

void MainWindow::on_action_Save_triggered()
{
    save();
}

void MainWindow::on_action_SaveAs_triggered()
{
    saveAs();
}

void MainWindow::on_action_Open_triggered()
{
    if(maybeSave()){
        QString fileName=QFileDialog::getOpenFileName(this);
        if(!fileName.isEmpty()){
            loadFile(fileName);
            ui->textEdit->setVisible(true);
        }
    }
}

void MainWindow::on_action_Close_triggered()
{
    if(maybeSave()){
        ui->textEdit->setVisible(false);
    }
}

void MainWindow::on_action_Exit_triggered()
{
    on_action_Close_triggered();
    qApp->quit();
}

void MainWindow::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_Cut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_action_Copy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_action_Paste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(maybeSave()){
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::showFindEdit()
{
    QString findString=findLineEdit->text();
    if(!ui->textEdit->find(findString, QTextDocument::FindBackward)){
        QMessageBox::warning(this,codec->toUnicode("查找"),codec->toUnicode("找不到%1").arg(findString));
    }
}

void MainWindow::on_action_Find_triggered()
{
    findDlg->show();
}
