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

//call this method: int ClientCommand::RegisterCommand( std::string username, std::string password )
// and signin for the user too: int ClientCommand::LoginCommand( std::string username, std::string password )
void SignUpDialog::on_signup_submit_accepted()
{
    std::string username = ui->signup_username_textedit->toPlainText().toStdString();
    std::string password = ui->signup_password_textedit->toPlainText().toStdString();
    std::string password_conf = ui->signup_passwordconf_textedit->toPlainText().toStdString();
//    qDebug << "password compare result is " << password.compare(password_conf) << "\n";
    if (password.compare(password_conf)!=0) {
        //TODO error popup (ONLY ONE INSTANCE FOR THIS CLASS, instantiate it with a message
        errorPopup->setError("password and password confirmation don't match");
        errorPopup->setModal(true);
        errorPopup->exec(); //TODO still not working
    } else {
        if (ClientCommandManager::clientCommand->LoginCommand(username, password) != 0) {//not successful
            //TODO error popup again
            errorPopup->setError("Login not successful");
            errorPopup->setModal(true);
            errorPopup->exec(); //TODO still not working
        }
    }
}
