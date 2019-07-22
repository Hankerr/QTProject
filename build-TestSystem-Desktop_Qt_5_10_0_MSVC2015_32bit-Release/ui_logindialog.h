/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label_3;
    QTextEdit *Login_textEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Username_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Password_lineEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *login_pushBtn;
    QPushButton *logincancle_pushButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->setWindowModality(Qt::WindowModal);
        LoginDialog->resize(446, 285);
        LoginDialog->setCursor(QCursor(Qt::ArrowCursor));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 10, 251, 31));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(16);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_3->setFont(font);
        Login_textEdit = new QTextEdit(LoginDialog);
        Login_textEdit->setObjectName(QStringLiteral("Login_textEdit"));
        Login_textEdit->setGeometry(QRect(200, 240, 241, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(10);
        Login_textEdit->setFont(font1);
        Login_textEdit->setReadOnly(true);
        widget = new QWidget(LoginDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(99, 60, 211, 98));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        Username_lineEdit = new QLineEdit(widget);
        Username_lineEdit->setObjectName(QStringLiteral("Username_lineEdit"));

        horizontalLayout->addWidget(Username_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);

        horizontalLayout_2->addWidget(label_2);

        Password_lineEdit = new QLineEdit(widget);
        Password_lineEdit->setObjectName(QStringLiteral("Password_lineEdit"));
        Password_lineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(Password_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        widget1 = new QWidget(LoginDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(100, 180, 211, 27));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        login_pushBtn = new QPushButton(widget1);
        login_pushBtn->setObjectName(QStringLiteral("login_pushBtn"));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        login_pushBtn->setFont(font3);

        horizontalLayout_3->addWidget(login_pushBtn);

        logincancle_pushButton = new QPushButton(widget1);
        logincancle_pushButton->setObjectName(QStringLiteral("logincancle_pushButton"));
        logincancle_pushButton->setFont(font3);

        horizontalLayout_3->addWidget(logincancle_pushButton);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        label_3->setText(QApplication::translate("LoginDialog", "\344\272\214\346\254\241\347\224\265\346\272\220\350\207\252\345\212\250\345\214\226\346\265\213\350\257\225\347\263\273\347\273\237", nullptr));
        Login_textEdit->setHtml(QApplication::translate("LoginDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Agency FB'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-weight:600;\">Depertment\357\274\232\345\215\216\344\270\272\344\272\214\346\254\241\347\224\265\346\272\220\346\265\213\350\257\225\351\203\250</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-weight:600;\">Author\357\274\232\346\210\277\346\240\271\346\240\271\357\274\210fwx545746\357\274\211</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("LoginDialog", "\345\257\206     \347\240\201\357\274\232", nullptr));
        login_pushBtn->setText(QApplication::translate("LoginDialog", "\347\231\273    \345\275\225", nullptr));
        logincancle_pushButton->setText(QApplication::translate("LoginDialog", "\345\217\226     \346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
