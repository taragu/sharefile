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
    QString ip_qstring = ui->ip_textedit->text();
    char * ip= new char[ip_qstring.length()+1];
    strcpy(ip, ip_qstring.toLatin1().constData());
    ClientCommand * clientCommandPointer = new ClientCommand(ip, ui->portnumber_textedit->text().toInt());
    ClientCommandManager::setClientCommand(clientCommandPointer);
    delete[] ip;
}


void ConnectDialog::on_buttonBox_rejected()
{

}
