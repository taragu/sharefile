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




void SignUpDialog::on_signup_submit_accepted()
{
    std::string username = ui->signup_username_textedit->text().toStdString();
    std::string password = ui->signup_password_textedit->text().toStdString();
    std::string password_conf = ui->signup_passwordconf_textedit->text().toStdString();
    if (password.compare(password_conf)!=0) {
        changeMessage("password and password confirmation don't match");
    } else {
        if (ClientCommandManager::clientCommand->LoginCommand(username, password) != 0) {//login not successful
            changeMessage("Login not successful");
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
