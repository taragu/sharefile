#include "signindialog.h"
#include "ui_signindialog.h"

SignInDialog::SignInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignInDialog)
{
    ui->setupUi(this);
    message = "";
}

SignInDialog::~SignInDialog()
{
    delete ui;
}

void SignInDialog::changeMessage(std::string _message) {
    message = _message;
    notify(message);
}

std::string SignInDialog::getMessage() {
    return message;
}
