/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Close;
    QAction *action_Save;
    QAction *action_SaveAs;
    QAction *action_Exit;
    QAction *action_Undo;
    QAction *action_Copy;
    QAction *action_Cut;
    QAction *action_Paste;
    QAction *action_Find;
    QAction *action_Version;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(631, 397);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/myimages/myimages/NewFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/myimages/myimages/AnFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        action_Close = new QAction(MainWindow);
        action_Close->setObjectName(QStringLiteral("action_Close"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/myimages/myimages/Copying.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Close->setIcon(icon2);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/myimages/myimages/SaveFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon3);
        action_SaveAs = new QAction(MainWindow);
        action_SaveAs->setObjectName(QStringLiteral("action_SaveAs"));
        action_SaveAs->setIcon(icon1);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/myimages/myimages/ExitFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon4);
        action_Undo = new QAction(MainWindow);
        action_Undo->setObjectName(QStringLiteral("action_Undo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/myimages/myimages/Cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Undo->setIcon(icon5);
        action_Copy = new QAction(MainWindow);
        action_Copy->setObjectName(QStringLiteral("action_Copy"));
        action_Copy->setIcon(icon2);
        action_Cut = new QAction(MainWindow);
        action_Cut->setObjectName(QStringLiteral("action_Cut"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/myimages/myimages/Cutting.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Cut->setIcon(icon6);
        action_Paste = new QAction(MainWindow);
        action_Paste->setObjectName(QStringLiteral("action_Paste"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/myimages/myimages/Paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Paste->setIcon(icon7);
        action_Find = new QAction(MainWindow);
        action_Find->setObjectName(QStringLiteral("action_Find"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/myimages/myimages/Finding.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Find->setIcon(icon8);
        action_Version = new QAction(MainWindow);
        action_Version->setObjectName(QStringLiteral("action_Version"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/myimages/myimages/Version.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Version->setIcon(icon9);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 631, 22));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addSeparator();
        menu_F->addSeparator();
        menu_F->addSeparator();
        menu_E->addSeparator();
        menu_E->addSeparator();
        mainToolBar->addSeparator();
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_New);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addAction(action_Close);
        mainToolBar->addAction(action_SaveAs);
        mainToolBar->addAction(action_Exit);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Copy);
        mainToolBar->addAction(action_Undo);
        mainToolBar->addAction(action_Cut);
        mainToolBar->addAction(action_Paste);
        mainToolBar->addAction(action_Find);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Version);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_New->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(N)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_New->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        action_Open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action_Close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&C)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Close->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        action_Save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_SaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", nullptr));
        action_Exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        action_Undo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&Z)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Undo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        action_Copy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Copy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        action_Cut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(&X)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Cut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        action_Paste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&V)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Paste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        action_Find->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242(&F)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Find->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        action_Version->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254\350\257\264\346\230\216(&V)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Version->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
