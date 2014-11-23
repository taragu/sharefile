#include "connectdialog.h"
#include "ui_connectdialog.h"
#include "clientcommand.h"
#include "clientcommandmanager.h"


ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::on_buttonBox_accepted()
{
    //store the ip address, create an instance of client command
    ClientCommandManager.createClientCommand(ui->ip_textedit->toPlainText().toStdString().c_str(),
                                                     ui->portnumber_textedit->toPlainText().toInt());
}
