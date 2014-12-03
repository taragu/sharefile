#include "addafrienddialog.h"
#include "ui_addafrienddialog.h"

AddAFriendDialog::AddAFriendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAFriendDialog)
{
    ui->setupUi(this);
    errorPopup = new ErrorPopup();
}

AddAFriendDialog::~AddAFriendDialog()
{
    delete errorPopup;
    delete ui;
}

void AddAFriendDialog::on_buttonBox_accepted()
{
    // call ClientCommand's method to add a friend
    QByteArray receiverByteArray = ui->receivername_lineedit->text().toUtf8();
    const char* receiver = receiverByteArray.constData();
    char message[] = "friend_request\0";
    // call client command to send a message
    int retVal = ClientCommandManager::clientCommand->SendCommand(receiver, (std::string)message);
    if (retVal == -1) {
//        char message[] = "SendCommand error\0";
        changeMessage( "SendCommand error\0");

    }
    if (retVal == 0) {
//        char message[] = "message sent!\0";
        changeMessage("message sent!\0");
    }
}

void AddAFriendDialog::changeMessage(std::string _message) {
    message = _message;
    notify(message);
}

std::string AddAFriendDialog::getMessage() {
    return message;
}
