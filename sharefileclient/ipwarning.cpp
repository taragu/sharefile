#include "ipwarning.h"
#include "ui_ipwarning.h"

IPWarning::IPWarning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IPWarning)
{
    ui->setupUi(this);
}

IPWarning::~IPWarning()
{
    delete ui;
}
