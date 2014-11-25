#include "errorpopup.h"
#include "ui_errorpopup.h"
#include <IObserver.h>

ErrorPopup::ErrorPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorPopup)
{
    ui->setupUi(this);
}

void ErrorPopup::update(std::string errorMsg) {
    ui->errormsg_label->setText(QString::fromUtf8(errorMsg.c_str()));
    this->setModal(true);
    this->exec();
}

ErrorPopup::~ErrorPopup()
{
    delete ui;
}


