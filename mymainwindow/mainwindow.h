#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>
#include <QCloseEvent>

//前置声明 与头文件声明的位置一致
class QLineEdit;
class QDialog;
class QLabel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool isUntitled;//为真表示没有保存过，为假表示文件已经保存过
    QString curFile;//保存当前文件的路径
public:
    void newFile();//新建操作
    bool maybeSave();//判断是否保存
    bool save();//保存
    bool saveAs();//另存为
    bool saveFile(const QString &fileName);//保存文件
    bool loadFile(const QString &fileName);//加载文件
public://处理中文乱码
    //设置编码格式为GBK
    QTextCodec *codec = QTextCodec::codecForName("GBK");
private slots:
    void on_action_New_triggered();
    void on_action_Save_triggered();
    void on_action_SaveAs_triggered();
    void on_action_Open_triggered();
    void on_action_Close_triggered();
    void on_action_Exit_triggered();
    void on_action_Undo_triggered();
    void on_action_Cut_triggered();
    void on_action_Copy_triggered();
    void on_action_Paste_triggered();
protected:
    void closeEvent(QCloseEvent *Event);
private:
    QLineEdit *findLineEdit;
    QDialog *findDlg;
    QLabel *statusLabel;
private slots:
    void showFindEdit();
    void on_action_Find_triggered();
};

#endif // MAINWINDOW_H
