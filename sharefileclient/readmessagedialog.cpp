#include "readmessagedialog.h"
#include "ui_readmessagedialog.h"

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
        //TODO: CALL ACCEPT FRIEND REQUEST METHOD IN CLIENTCOMMAND
    }
    //if this is a normal message, nothing will happen when user clicks 'ok'
}

void ReadMessageDialog::on_decline_button_clicked()
{
    if (isARequest) {
        //TODO: CALL DECLINE FRIEND REQUEST METHOD IN CLIENTCOMMAND
    }
    //if this is a normal message, the decline button will be hidden
}
