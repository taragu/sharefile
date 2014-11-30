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
    attach(errorPopup);
    QByteArray userByteArray = ui->signin_username_textedit->text().toUtf8();
    const char* username = userByteArray.constData();
    QByteArray passwordByteArray = ui->signin_password_textedit->text().toUtf8();
    const char* password = passwordByteArray.constData();

        QCryptographicHash md5Generator(QCryptographicHash::Md5);
        md5Generator.addData(password);
        int login_ret = ClientCommandManager::clientCommand->LoginCommand((std::string)username, (std::string)md5Generator.result().toHex());
        if (login_ret!=0) {
            char message[] = "Login not successful\0";
            changeMessage((std::string) message);
        } else {
             usersController->setSignedIn(true);
             usersController->setUsername((std::string)username);
             char message[] = "Login success!\0";
             changeMessage((std::string) message);
        }
        detach(errorPopup);
}
