#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "clientcommandmanager.h"
#include "QDebug"
#include <QCryptographicHash>
#include <string>

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
    QByteArray userByteArray = ui->signup_username_textedit->text().toUtf8();
    const char* username = userByteArray.constData();
    std::string username_string = (std::string) username;
    QByteArray passwordByteArray = ui->signup_password_textedit->text().toUtf8();
    const char* password = passwordByteArray.constData();
    QByteArray passwordConfByteArray = ui->signup_passwordconf_textedit->text().toUtf8();
    const char* password_conf = passwordConfByteArray.constData();
    //check if there's any special characters in the username
    if (username_string.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos) {
      char message[] = "you cannot have special character(s) in your username!\0";
      changeMessage((std::string) message);
    } else if (strcmp(password, password_conf)!=0) {
        char message[] = "password and password confirmation don't match\0";
        changeMessage((std::string)message);
    } else {
        //signup
        QCryptographicHash md5Generator(QCryptographicHash::Md5);
        md5Generator.addData(password);
        std::string * username_string = new std::string(username);
        int signup_ret = ClientCommandManager::clientCommand->LogonCommand(*username_string, (std::string)md5Generator.result().toHex());
        if (signup_ret!=0) {
//            char message[] = "Signup error: username already exists\0";
            changeMessage("Signup error: username already exists\0");
        } else {
            usersController->setSignedIn(true);
            usersController->setUsername(*username_string);
//            char message[] = "login success!\0";
            changeMessage("login success\0");
        }
        delete username_string;
    }

}

void SignUpDialog::changeMessage(std::string _message) {
    message = _message;
    notify(message);
}

std::string SignUpDialog::getMessage() {
    return message;
}
