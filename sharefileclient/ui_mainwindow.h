/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(714, 556);
        actionSignin = new QAction(MainWindow);
        actionSignin->setObjectName(QStringLiteral("actionSignin"));
        actionSignup = new QAction(MainWindow);
        actionSignup->setObjectName(QStringLiteral("actionSignup"));
        actionSignup->setCheckable(true);
        actionAdd_a_friend = new QAction(MainWindow);
        actionAdd_a_friend->setObjectName(QStringLiteral("actionAdd_a_friend"));
        actionChat_with_a_friend = new QAction(MainWindow);
        actionChat_with_a_friend->setObjectName(QStringLiteral("actionChat_with_a_friend"));
        actionFriend_requests = new QAction(MainWindow);
        actionFriend_requests->setObjectName(QStringLiteral("actionFriend_requests"));
        actionMessages = new QAction(MainWindow);
        actionMessages->setObjectName(QStringLiteral("actionMessages"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 120, 131, 21));
        serverfiles_list = new QListWidget(centralWidget);
        serverfiles_list->setObjectName(QStringLiteral("serverfiles_list"));
        serverfiles_list->setGeometry(QRect(30, 150, 301, 251));
        upload_button = new QPushButton(centralWidget);
        upload_button->setObjectName(QStringLiteral("upload_button"));
        upload_button->setGeometry(QRect(450, 60, 81, 31));
        signup_button = new QPushButton(centralWidget);
        signup_button->setObjectName(QStringLiteral("signup_button"));
        signup_button->setGeometry(QRect(140, 0, 99, 27));
        connect_button = new QPushButton(centralWidget);
        connect_button->setObjectName(QStringLiteral("connect_button"));
        connect_button->setGeometry(QRect(360, 0, 99, 27));
        signin_button = new QPushButton(centralWidget);
        signin_button->setObjectName(QStringLiteral("signin_button"));
        signin_button->setGeometry(QRect(250, 0, 99, 27));
        add_a_friend_button = new QPushButton(centralWidget);
        add_a_friend_button->setObjectName(QStringLiteral("add_a_friend_button"));
        add_a_friend_button->setGeometry(QRect(470, 0, 99, 27));
        sharefile_button = new QPushButton(centralWidget);
        sharefile_button->setObjectName(QStringLiteral("sharefile_button"));
        sharefile_button->setGeometry(QRect(80, 440, 211, 41));
        browse_path_lineedit = new QLineEdit(centralWidget);
        browse_path_lineedit->setObjectName(QStringLiteral("browse_path_lineedit"));
        browse_path_lineedit->setGeometry(QRect(150, 60, 281, 31));
        browse_button = new QPushButton(centralWidget);
        browse_button->setObjectName(QStringLiteral("browse_button"));
        browse_button->setGeometry(QRect(30, 60, 99, 27));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(400, 150, 281, 261));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(490, 120, 111, 16));
        exit_button = new QPushButton(centralWidget);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        exit_button->setGeometry(QRect(530, 480, 99, 27));
        friend_lineedit = new QLineEdit(centralWidget);
        friend_lineedit->setObjectName(QStringLiteral("friend_lineedit"));
        friend_lineedit->setGeometry(QRect(50, 420, 271, 21));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSignin->setText(QApplication::translate("MainWindow", "Sign in", 0));
        actionSignup->setText(QApplication::translate("MainWindow", "Sign up", 0));
        actionAdd_a_friend->setText(QApplication::translate("MainWindow", "Add a friend", 0));
        actionChat_with_a_friend->setText(QApplication::translate("MainWindow", "Chat with a friend", 0));
        actionFriend_requests->setText(QApplication::translate("MainWindow", "Friend requests", 0));
        actionMessages->setText(QApplication::translate("MainWindow", "Messages", 0));
        label_3->setText(QApplication::translate("MainWindow", "Uploaded Files", 0));
        upload_button->setText(QApplication::translate("MainWindow", "Upload!", 0));
        signup_button->setText(QApplication::translate("MainWindow", "Sign up", 0));
        connect_button->setText(QApplication::translate("MainWindow", "Enter IP", 0));
        signin_button->setText(QApplication::translate("MainWindow", "Sign in", 0));
        add_a_friend_button->setText(QApplication::translate("MainWindow", "Add a Friend", 0));
        sharefile_button->setText(QApplication::translate("MainWindow", "Share Selected Files with...", 0));
        browse_button->setText(QApplication::translate("MainWindow", "Browse", 0));
        label_2->setText(QApplication::translate("MainWindow", "Your Friends", 0));
        exit_button->setText(QApplication::translate("MainWindow", "EXIT", 0));
        friend_lineedit->setPlaceholderText(QApplication::translate("MainWindow", "Type your friend's user name here", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
