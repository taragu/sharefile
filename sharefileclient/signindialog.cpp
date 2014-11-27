#include "signindialog.h"
#include "ui_signindialog.h"
#include "clientcommandmanager.h"

SignInDialog::SignInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignInDialog)
{
    ui->setupUi(this);
    message = "";
    errorPopup = new ErrorPopup();
    attach(errorPopup);
}

SignInDialog::~SignInDialog()
{
    delete errorPopup;
    delete ui;
}

void SignInDialog::changeMessage(std::string _message) {
    message = _message;
    notify(message);
}

std::string SignInDialog::getMessage() {
    return message;
}

void SignInDialog::setUsersController(UsersController* _usersController) {
    usersController = _usersController;
}

void SignInDialog::on_signin_submit_accepted()
{
        std::string username = ui->signin_username_textedit->text().toStdString();
        std::string password = ui->signin_password_textedit->text().toStdString();
        int login_ret = ClientCommandManager::clientCommand->LoginCommand(username, password) != 0;
        //then login
        if (login_ret) {
                 changeMessage("Login not successful");
        } else {
             usersController->setSignedIn(true);
             usersController->setUsername(username);
                changeMessage("login success!");
        }
}
