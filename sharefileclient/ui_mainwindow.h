/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSignin;
    QAction *actionSignup;
    QAction *actionAdd_a_friend;
    QAction *actionChat_with_a_friend;
    QAction *actionFriend_requests;
    QAction *actionMessages;
    QWidget *centralWidget;
    QLabel *label_3;
    QListWidget *serverfiles_list;
    QPushButton *upload_button;
    QPushButton *signup_button;
    QPushButton *connect_button;
    QPushButton *signin_button;
    QPushButton *add_a_friend_button;
    QPushButton *sharefile_button;
    QLineEdit *browse_path_lineedit;
    QPushButton *browse_button;
    QListWidget *listWidget;
    QLabel *label_2;
    QPushButton *exit_button;
    QLineEdit *friend_lineedit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(714, 556);
        actionSignin = new QAction(MainWindow);
        actionSignin->setObjectName(QString::fromUtf8("actionSignin"));
        actionSignup = new QAction(MainWindow);
        actionSignup->setObjectName(QString::fromUtf8("actionSignup"));
        actionSignup->setCheckable(true);
        actionAdd_a_friend = new QAction(MainWindow);
        actionAdd_a_friend->setObjectName(QString::fromUtf8("actionAdd_a_friend"));
        actionChat_with_a_friend = new QAction(MainWindow);
        actionChat_with_a_friend->setObjectName(QString::fromUtf8("actionChat_with_a_friend"));
        actionFriend_requests = new QAction(MainWindow);
        actionFriend_requests->setObjectName(QString::fromUtf8("actionFriend_requests"));
        actionMessages = new QAction(MainWindow);
        actionMessages->setObjectName(QString::fromUtf8("actionMessages"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 120, 131, 21));
        serverfiles_list = new QListWidget(centralWidget);
        serverfiles_list->setObjectName(QString::fromUtf8("serverfiles_list"));
        serverfiles_list->setGeometry(QRect(30, 150, 301, 251));
        upload_button = new QPushButton(centralWidget);
        upload_button->setObjectName(QString::fromUtf8("upload_button"));
        upload_button->setGeometry(QRect(450, 60, 81, 31));
        signup_button = new QPushButton(centralWidget);
        signup_button->setObjectName(QString::fromUtf8("signup_button"));
        signup_button->setGeometry(QRect(140, 0, 99, 27));
        connect_button = new QPushButton(centralWidget);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));
        connect_button->setGeometry(QRect(360, 0, 99, 27));
        signin_button = new QPushButton(centralWidget);
        signin_button->setObjectName(QString::fromUtf8("signin_button"));
        signin_button->setGeometry(QRect(250, 0, 99, 27));
        add_a_friend_button = new QPushButton(centralWidget);
        add_a_friend_button->setObjectName(QString::fromUtf8("add_a_friend_button"));
        add_a_friend_button->setGeometry(QRect(470, 0, 99, 27));
        sharefile_button = new QPushButton(centralWidget);
        sharefile_button->setObjectName(QString::fromUtf8("sharefile_button"));
        sharefile_button->setGeometry(QRect(80, 440, 211, 41));
        browse_path_lineedit = new QLineEdit(centralWidget);
        browse_path_lineedit->setObjectName(QString::fromUtf8("browse_path_lineedit"));
        browse_path_lineedit->setGeometry(QRect(150, 60, 281, 31));
        browse_button = new QPushButton(centralWidget);
        browse_button->setObjectName(QString::fromUtf8("browse_button"));
        browse_button->setGeometry(QRect(30, 60, 99, 27));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(400, 150, 281, 261));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(490, 120, 111, 16));
        exit_button = new QPushButton(centralWidget);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setGeometry(QRect(530, 480, 99, 27));
        friend_lineedit = new QLineEdit(centralWidget);
        friend_lineedit->setObjectName(QString::fromUtf8("friend_lineedit"));
        friend_lineedit->setGeometry(QRect(50, 420, 271, 21));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSignin->setText(QApplication::translate("MainWindow", "Sign in", 0, QApplication::UnicodeUTF8));
        actionSignup->setText(QApplication::translate("MainWindow", "Sign up", 0, QApplication::UnicodeUTF8));
        actionAdd_a_friend->setText(QApplication::translate("MainWindow", "Add a friend", 0, QApplication::UnicodeUTF8));
        actionChat_with_a_friend->setText(QApplication::translate("MainWindow", "Chat with a friend", 0, QApplication::UnicodeUTF8));
        actionFriend_requests->setText(QApplication::translate("MainWindow", "Friend requests", 0, QApplication::UnicodeUTF8));
        actionMessages->setText(QApplication::translate("MainWindow", "Messages", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Uploaded Files", 0, QApplication::UnicodeUTF8));
        upload_button->setText(QApplication::translate("MainWindow", "Upload!", 0, QApplication::UnicodeUTF8));
        signup_button->setText(QApplication::translate("MainWindow", "Sign up", 0, QApplication::UnicodeUTF8));
        connect_button->setText(QApplication::translate("MainWindow", "Enter IP", 0, QApplication::UnicodeUTF8));
        signin_button->setText(QApplication::translate("MainWindow", "Sign in", 0, QApplication::UnicodeUTF8));
        add_a_friend_button->setText(QApplication::translate("MainWindow", "Add a Friend", 0, QApplication::UnicodeUTF8));
        sharefile_button->setText(QApplication::translate("MainWindow", "Share Selected Files with...", 0, QApplication::UnicodeUTF8));
        browse_button->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Your Friends", 0, QApplication::UnicodeUTF8));
        exit_button->setText(QApplication::translate("MainWindow", "EXIT", 0, QApplication::UnicodeUTF8));
        friend_lineedit->setPlaceholderText(QApplication::translate("MainWindow", "Type your friend's user name here", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
