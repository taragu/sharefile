#include "frienddialog.h"
#include "ui_frienddialog.h"

//pops up when user clicks on a friend on the friend list; send a message to a friend; unfriend

FriendDialog::FriendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendDialog)
{
    ui->setupUi(this);
}

FriendDialog::~FriendDialog()
{
    delete ui;
}
