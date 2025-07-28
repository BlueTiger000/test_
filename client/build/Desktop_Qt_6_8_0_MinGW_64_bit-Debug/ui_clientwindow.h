/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *ip_adress;
    QLabel *label;
    QLineEdit *port_name;
    QLabel *label_2;
    QLineEdit *client_name;
    QLabel *label_3;
    QLineEdit *enter_text;
    QLabel *label_4;
    QTextEdit *Message_box;
    QLabel *label_5;
    QPushButton *push_message;
    QPushButton *connect_with_server;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName("ClientWindow");
        ClientWindow->resize(800, 600);
        centralwidget = new QWidget(ClientWindow);
        centralwidget->setObjectName("centralwidget");
        ip_adress = new QLineEdit(centralwidget);
        ip_adress->setObjectName("ip_adress");
        ip_adress->setGeometry(QRect(20, 50, 171, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 91, 41));
        port_name = new QLineEdit(centralwidget);
        port_name->setObjectName("port_name");
        port_name->setGeometry(QRect(220, 50, 171, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 20, 63, 20));
        client_name = new QLineEdit(centralwidget);
        client_name->setObjectName("client_name");
        client_name->setGeometry(QRect(420, 50, 201, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(420, 20, 161, 20));
        enter_text = new QLineEdit(centralwidget);
        enter_text->setObjectName("enter_text");
        enter_text->setGeometry(QRect(20, 150, 451, 81));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 110, 211, 20));
        Message_box = new QTextEdit(centralwidget);
        Message_box->setObjectName("Message_box");
        Message_box->setGeometry(QRect(20, 280, 451, 141));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 240, 241, 20));
        push_message = new QPushButton(centralwidget);
        push_message->setObjectName("push_message");
        push_message->setGeometry(QRect(20, 440, 171, 51));
        connect_with_server = new QPushButton(centralwidget);
        connect_with_server->setObjectName("connect_with_server");
        connect_with_server->setGeometry(QRect(220, 440, 171, 51));
        ClientWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClientWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        ClientWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ClientWindow);
        statusbar->setObjectName("statusbar");
        ClientWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(ClientWindow);

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWindow)
    {
        ClientWindow->setWindowTitle(QCoreApplication::translate("ClientWindow", "ClientWindow", nullptr));
        label->setText(QCoreApplication::translate("ClientWindow", "IP \321\201\320\265\321\200\320\262\320\265\321\200\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWindow", "\320\237\320\276\321\200\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("ClientWindow", "\320\230\320\274\321\217 \320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("ClientWindow", "\320\222\320\260\321\210\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_5->setText(QCoreApplication::translate("ClientWindow", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
        push_message->setText(QCoreApplication::translate("ClientWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        connect_with_server->setText(QCoreApplication::translate("ClientWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        menu->setTitle(QCoreApplication::translate("ClientWindow", "\321\207\320\260\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
