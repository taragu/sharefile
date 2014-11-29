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

//TODO
//ok onclick: different for isARequest and is not
//decline button onclick: decline friend request
