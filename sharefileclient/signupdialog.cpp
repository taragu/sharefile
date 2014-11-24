#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "clientcommandmanager.h"

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
    if (password!=password_conf) {
        //TODO error popup (ONLY ONE INSTANCE FOR THIS CLASS, instantiate it with a message
        //use this ui->errormsg_label->setText(test);
        Ui::ErrorPopup * errorUI = errorPopup->getUI();
        errorUI->errormsg_label->setText("password and password confirmation don't match");

    } else {
        if (ClientCommandManager::clientCommand->LoginCommand(username, password) != 0) {//not successful
            //TODO error popup again
        }
    }
}
