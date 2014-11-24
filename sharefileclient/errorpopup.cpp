#include "errorpopup.h"
#include "ui_errorpopup.h"

ErrorPopup::ErrorPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorPopup)
{
    ui->setupUi(this);
}

Ui::ErrorPopup * getUI() {
    return ui;
}

ErrorPopup::~ErrorPopup()
{
    delete ui;
}


