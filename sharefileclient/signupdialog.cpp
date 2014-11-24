#include "signupdialog.h"
#include "ui_signupdialog.h"

SignUpDialog::SignUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpDialog)
{
    ui->setupUi(this);
}

SignUpDialog::~SignUpDialog()
{
    delete ui;
}

//call this method: int ClientCommand::RegisterCommand( std::string username, std::string password )
// and signin for the user too: int ClientCommand::LoginCommand( std::string username, std::string password )


