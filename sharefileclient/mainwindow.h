#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ipwarning.h>
#include <signinwarning.h>
#include <signupdialog.h>
#include <signindialog.h>
#include <messagesubject.h>

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
//    void on_pushButton_clicked();

    void on_movefiles_button_clicked();

    void on_signup_button_clicked();

    void on_connect_button_clicked();

    void on_cd_button_clicked();

    void on_signin_button_clicked();

    void changeMessage(std::string string);

    std::string getMessage();

private:
    IPWarning * ipWarning;
    SigninWarning * signinWarning;
    Ui::MainWindow *ui;
    SignUpDialog * signupDialog;
    SignInDialog * signinDialog;
    std::string message;

};

#endif // MAINWINDOW_H
