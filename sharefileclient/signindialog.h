#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>
#include <string>
#include "messagesubject.h"
#include "userscontroller.h"

namespace Ui {
class SignInDialog;
}

class SignInDialog : public QDialog, public MessageSubject
{
    Q_OBJECT

public:
    explicit SignInDialog(QWidget *parent = 0);
    ~SignInDialog();
    void setUsersController(UsersController *);


private slots:
    void on_signin_submit_accepted();

private:
    Ui::SignInDialog *ui;
    std::string message;
    ErrorPopup * errorPopup;
    UsersController * usersController;
    void changeMessage(std::string message);
    std::string getMessage();
};

#endif // SIGNINDIALOG_H
