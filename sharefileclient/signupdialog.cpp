#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "clientcommandmanager.h"
#include "QDebug"

SignUpDialog::SignUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpDialog)
{
    ui->setupUi(this);
    errorPopup = new ErrorPopup();
    message = "";
    attach(errorPopup);
}

SignUpDialog::~SignUpDialog()
{
    delete errorPopup;
    delete ui;
}

void SignUpDialog::setUsersController(UsersController* _usersController) {
    usersController = _usersController;
}

void SignUpDialog::on_signup_submit_accepted()
{
    std::string username = ui->signup_username_textedit->text().toStdString();
    std::string password = ui->signup_password_textedit->text().toStdString();
    std::string password_conf = ui->signup_passwordconf_textedit->text().toStdString();
    if (password.compare(password_conf)!=0) {
        changeMessage("password and password confirmation don't match");
    } else {
        //signup
        qDebug("before registration\n");
        int signup_ret = ClientCommandManager::clientCommand->LogonCommand(username, password);
        qDebug("after registration\n");
        if (signup_ret!=0) {
            changeMessage("Signup error: username already exists");
        } else {
            usersController->setSignedIn(true);
            usersController->setUsername(username);
            changeMessage("login success!");

        }
    }
}

void SignUpDialog::changeMessage(std::string _message) {
    message = _message;
    notify(message);
}

std::string SignUpDialog::getMessage() {
    return message;
}
