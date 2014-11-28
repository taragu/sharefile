#include "addafrienddialog.h"
#include "ui_addafrienddialog.h"

AddAFriendDialog::AddAFriendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAFriendDialog)
{
    ui->setupUi(this);
}

AddAFriendDialog::~AddAFriendDialog()
{
    delete ui;
}

void AddAFriendDialog::on_buttonBox_accepted()
{
    //TODO call ClientCommand's method to add a friend
}
