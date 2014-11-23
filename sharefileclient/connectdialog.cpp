#include "connectdialog.h"
#include "ui_connectdialog.h"
#include "clientcommand.h"
#include "clientcommandmanager.h"

ClientCommand * ClientCommandManager::clientCommand;

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
    char * ip = strstr((char *)ui->ip_textedit->toPlainText().toStdString().c_str(),"550");
    ClientCommandManager::clientCommand = new ClientCommand(ip, ui->portnumber_textedit->toPlainText().toInt());
    ClientCommandManager::clientCommand->manager() ;
}
