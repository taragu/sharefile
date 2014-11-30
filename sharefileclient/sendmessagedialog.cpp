#include "sendmessagedialog.h"
#include "ui_sendmessagedialog.h"

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
    //TODO call client command to send a message
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
