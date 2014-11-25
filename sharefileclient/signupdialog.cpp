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
        errorPopup->setError("password and password confirmation don't match");
        errorPopup->setModal(true);
        errorPopup->exec();
    } else {
        if (ClientCommandManager::clientCommand->LoginCommand(username, password) != 0) {//login not successful
            errorPopup->setError("Login not successful");
            errorPopup->setModal(true);
            errorPopup->exec();
        }
    }
}
