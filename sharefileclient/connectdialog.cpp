#include "connectdialog.h"
#include "ui_connectdialog.h"
#include "clientcommand.h"
#include "clientcommandmanager.h"
#include "mainwindow.h"
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
    qDebug() << "ip plain text to latin data is " <<  ui->ip_textedit->toPlainText().toLatin1().data()<< "\n";
    char * ip = ui->ip_textedit->toPlainText().toLatin1().data();
    ClientCommand * clientCommandPointer = new ClientCommand(ip, ui->portnumber_textedit->toPlainText().toInt());
    ClientCommandManager::setClientCommand(clientCommandPointer);
//    ClientCommandManager::clientCommand->manager() ;
}


void ConnectDialog::on_buttonBox_rejected()
{

}
