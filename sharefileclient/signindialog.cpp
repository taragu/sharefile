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
    std::string * username_string = new std::string(username);
    int login_ret = ClientCommandManager::clientCommand->LoginCommand(*username_string, (std::string)md5Generator.result().toHex());
    if (login_ret!=0) {
//            char message[] = "Login not successful\0";
        changeMessage("Login not successful\0");
    } else {
        usersController->setSignedIn(true);
        usersController->setUsername(*username_string);
//             char message[] = "Login success!\0";
        changeMessage("Login success!\0");
    }
    detach(errorPopup);
    delete username_string;
}
