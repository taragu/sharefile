#include "friendrequestpopup.h"
#include "ui_friendrequestpopup.h"

FriendRequestPopup::FriendRequestPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendRequestPopup)
{
    ui->setupUi(this);
}

FriendRequestPopup::~FriendRequestPopup()
{
    delete ui;
}

void FriendRequestPopup::update(std::string friendName) {
//    ui->errormsg_label->setText(QString::fromUtf8(errorMsg.c_str()));
    //set text to friendName + " wants to be your friend!";
    ui->friendName_label->setText(QString::fromUtf8(friendName.c_str()));
    this->setModal(true);
    this->exec();
}

//TODO onclick: accept and decline
//accept: call ClientCommand's acceptFriendRequest method
//decline: call ClientCommand's declineFriendRequest method

