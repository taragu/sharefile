#include "sendmessagedialog.h"
#include "ui_sendmessagedialog.h"
#include "clientcommandmanager.h"
#include "clientcommand.h"

SendMessageDialog::SendMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendMessageDialog)
{
    ui->setupUi(this);
    errorPopup = new ErrorPopup();
    attach(errorPopup);
}

SendMessageDialog::~SendMessageDialog()
{
    delete errorPopup;
    delete ui;
}

void SendMessageDialog::on_buttonBox_accepted()
{
    QByteArray receiverByteArray = ui->friendname_lineedit->text().toUtf8();
    const char* receiver = receiverByteArray.constData();
    QByteArray messageByteArray = ui->message_textedit->toPlainText().toUtf8();
    const char* message = messageByteArray.constData();
    // call client command to send a message
    int retVal = ClientCommandManager::clientCommand->SendCommand(receiver, message);
    if (retVal == -1) {
        char message[] = "SendCommand error\0";
        changeMessage((std::string) message);
    }
    if (retVal == 0) {
        char message[] = "message sent!\0";
        changeMessage((std::string) message);
    }
}

void SendMessageDialog::on_unfriend_button_clicked()
{
    if (ui->friendname_lineedit->text().isEmpty()) {
        char message[] = "please enter your \"friend\"'s name first!\0";
        changeMessage((std::string) message);
        return;
    }
    QByteArray friendNameByteArray = ui->friendname_lineedit->text().toUtf8();
    const char* friendName = friendNameByteArray.constData();
    //TODO CALL CLIENTCOMMAND TO UNFRIEND
}

void SendMessageDialog::changeMessage(std::string _message) {
    message = _message;
    notify(message);
}

std::string SendMessageDialog::getMessage() {
    return message;
}

void SendMessageDialog::setReceiver(std::string username) {
    QString qstr = QString::fromStdString(username);
    ui->friendname_lineedit->setText(qstr);
}
