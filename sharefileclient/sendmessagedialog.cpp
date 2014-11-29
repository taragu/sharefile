#include "sendmessagedialog.h"
#include "ui_sendmessagedialog.h"

SendMessageDialog::SendMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendMessageDialog)
{
    ui->setupUi(this);
}

SendMessageDialog::~SendMessageDialog()
{
    delete ui;
}
