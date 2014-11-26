#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signupdialog.h"
#include "signindialog.h"
#include "messagesubject.h"
#include "userscontroller.h"
#include "friendrequestpopup.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public MessageSubject
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_upload_button_clicked();

    void on_signup_button_clicked();

    void on_connect_button_clicked();

    void on_signin_button_clicked();

    void changeMessage(std::string string);

    std::string getMessage();

private:
    Ui::MainWindow *ui;
    SignUpDialog * signupDialog;
    SignInDialog * signinDialog;
    std::string message;
    ErrorPopup * errorPopup;
    FriendRequestPopup * friendRequest;
    UsersController * usersController;
};

#endif // MAINWINDOW_H
