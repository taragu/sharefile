#include "readmessagedialog.h"
#include "ui_readmessagedialog.h"
#include "clientcommandmanager.h"
#include "clientcommand.h"

ReadMessageDialog::ReadMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReadMessageDialog)
{
    ui->setupUi(this);
    ui->decline_button->hide();
}

ReadMessageDialog::~ReadMessageDialog()
{
    delete ui;
}

void ReadMessageDialog::setIsARequest(bool _isARequest) {
    isARequest = _isARequest;
    ui->message_label->setText("I want to be your friend");
    //make the decline button visible TODO
    ui->decline_button->show();
}

void ReadMessageDialog::on_buttonBox_accepted()
{
    if (isARequest) {
        // SEND FRIEND REQUEST
        QByteArray receiverByteArray = ui->sendername_lineedit->text().toUtf8();
        const char* receiver = receiverByteArray.constData();
        char message [] = "friend\0";
        ClientCommandManager::clientCommand->SendCommand((std::string) receiver, (std::string) message);
    }
    //if this is a normal message, nothing will happen when user clicks 'ok'
}

void ReadMessageDialog::on_decline_button_clicked()
{
    if (isARequest) {
        //nothing happens; the request will still preserved in the database so that in the future the user can still accept the friend request
    }
    //if this is a normal message, the decline button will be hidden
}

void ReadMessageDialog::setSenderName(std::string username) {
    QString qstr = QString::fromStdString(username);
    ui->sendername_lineedit->setText(qstr);
}

void ReadMessageDialog::setMessage(std::string message) {
    QString qstr = QString::fromStdString(message);
    ui->message_label->setText(qstr);
}
