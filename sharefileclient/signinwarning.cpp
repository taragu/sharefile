#include "signinwarning.h"
#include "ui_signinwarning.h"

SigninWarning::SigninWarning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SigninWarning)
{
    ui->setupUi(this);
}

SigninWarning::~SigninWarning()
{
    delete ui;
}
