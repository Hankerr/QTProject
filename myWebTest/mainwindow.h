#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets>
#include <QWebEngineView>
#include <QLineEdit>

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
private slots:
    void changeLocation();
    void setProgress(int);
    void adjustTitle();
    void finishLoading(bool);
private:
    QWebEngineView *view;
    QLineEdit *locationEdit;
    int progress;

};

#endif // MAINWINDOW_H
