#include "signindialog.h"
#include "ui_signindialog.h"
#include "clientcommandmanager.h"
#include <QCryptographicHash>

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
        QCryptographicHash md5Generator(QCryptographicHash::Md5);
        md5Generator.addData(password.c_str());
        int login_ret = ClientCommandManager::clientCommand->LoginCommand(username, (std::string)md5Generator.result().toHex()) != 0;
        if (login_ret) {
            char message[] = "Login not successful\0";
            changeMessage((std::string) message);
        } else {
             usersController->setSignedIn(true);
             usersController->setUsername(username);
             char message[] = "Login success!\0";
             changeMessage((std::string) message);
        }
}
