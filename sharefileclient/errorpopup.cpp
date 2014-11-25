#include "errorpopup.h"
#include "ui_errorpopup.h"

ErrorPopup::ErrorPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorPopup)
{
    ui->setupUi(this);
}

void ErrorPopup::setError(std::string errorMsg) {
    ui->errormsg_label->setText(QString::fromUtf8(errorMsg.c_str()));
}

ErrorPopup::~ErrorPopup()
{
    delete ui;
}


