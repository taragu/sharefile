#include "connectdialog.h"
#include "ui_connectdialog.h"
#include "clientcommand.h"
#include "clientcommandmanager.h"
#include <iostream>
#include <string>
#include <QDebug>

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
    qDebug() << "BEFORE ANYTHING" << "\n";
    char * ip = strstr((char *)ui->ip_textedit->toPlainText().toStdString().c_str(),"550");
    qDebug() << "BEFORE CONSTRUCTING CLIENTCOMMAND" << "\n";
    ClientCommand * clientCommandPointer = new ClientCommand(ip, ui->portnumber_textedit->toPlainText().toInt());
    ClientCommandManager::setClientCommand(clientCommandPointer);
    qDebug() << "AFTER CONSTRUCTING CLIENTCOMMAND" << "\n";
    ClientCommandManager::clientCommand->manager() ;
}
