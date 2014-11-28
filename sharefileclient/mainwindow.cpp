#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signupdialog.h"
#include "connectdialog.h"
#include "clientcommand.h"
#include "clientcommandmanager.h"
#include <iostream>
#include <string>
#include <set>
#include <QDebug>
#include <QFileDialog>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    message = "";
    usersController = new UsersController();
    errorPopup = new ErrorPopup();
    friendRequest = new FriendRequestPopup();
    addAFriendDialog = new AddAFriendDialog();
    signupDialog = new SignUpDialog();
    signinDialog = new SignInDialog();
    attach(errorPopup); //IMPORTANT!!! observer pattern
}

void MainWindow::destroyAll(){
    delete ui;
    delete signupDialog;
    delete signinDialog;
    delete errorPopup;
    delete friendRequest;
    delete usersController;
    delete addAFriendDialog;
}

MainWindow::~MainWindow()
{
    destroyAll();
}

void MainWindow::on_signup_button_clicked()
{
    qDebug("signup botton clicked\n");
    if (ClientCommandManager::clientCommand == NULL) {
        char message[] = "please enter IP first!\0";
        changeMessage((std::string) message);
        return;
    } else {
       signupDialog->setUsersController(usersController);
       signupDialog->setModal(true);
       signupDialog->exec();
    }
}

//open dialog to enter ip address
void MainWindow::on_connect_button_clicked()
{
    ConnectDialog connect;
    connect.setModal(true);
    connect.exec();
}

void MainWindow::on_signin_button_clicked()
{
    if (ClientCommandManager::clientCommand == NULL) {
        char message[] = "please enter IP first!\0";
        changeMessage((std::string) message);
        return;
    } else {
        signinDialog->setUsersController(usersController);
        signinDialog->setModal(true);
        signinDialog->exec();
    }
}

void MainWindow::changeMessage(std::string _message) {
    message = _message;
    notify(message);
}

std::string MainWindow::getMessage() {
    return message;
}

void MainWindow::on_exit_button_clicked()
{
    this->close();
}

void MainWindow::on_add_a_friend_button_clicked()
{
    if (ClientCommandManager::clientCommand == NULL) {
        char message[] = "please enter IP first!\0";
        changeMessage((std::string) message);
        return;
    } else if (usersController->isSignedIn() == false) {
        char message[] = "please sign in first!\0";
        changeMessage((std::string) message);
        return;
    } else {
        addAFriendDialog->setModal(true);
        addAFriendDialog->exec();
    }
}

void MainWindow::on_browse_button_clicked()
{
    if (ClientCommandManager::clientCommand == NULL) {
        char message[] = "please enter IP first!\0";
        changeMessage((std::string) message);
        return;
    } else if (usersController->isSignedIn() == false) {
        char message[] = "please sign in first\0";
        changeMessage((std::string) message);
        return;
    } else {
        //when the user selects a file, the path of that file goes into the browse_path_lineedit
        QString fileName = QFileDialog::getOpenFileName(this, tr("Select File"), "/", "All files (*.*)");
        ui->browse_path_lineedit->setText(fileName);
    }
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
void MainWindow::on_upload_button_clicked()
{
    if (ClientCommandManager::clientCommand == NULL) {
        char message[] = "please enter IP first!\0";
        changeMessage((std::string) message);
        return;
    } else if (usersController->isSignedIn() == false) {
        char message[] = "please sign in first!\0";
        changeMessage((std::string) message);
        return;
    } else {
        //first copy the file on the file path to the user's directory
        std::string currentPath = QDir::currentPath().toStdString();
        std::string dest = currentPath + "/" + usersController->getUsername();
        std::string source_filepath = ui->browse_path_lineedit->text().toStdString();
        std::vector<std::string> seglist = split(source_filepath, '/');
        std::string fileName = seglist[seglist.size()-1];
        std::string dest_filepath = dest + "/"+ fileName;
        QFile::copy(QString::fromStdString(source_filepath), QString::fromStdString(dest_filepath));
        //then grab the filename of the file (should be in the user's directory) and use the put command
        ClientCommandManager::clientCommand->PutCommand(fileName);
    }
}

void MainWindow::on_sharefile_button_clicked()
{
    if (ClientCommandManager::clientCommand == NULL) {
        char message[] = "please enter IP first!\0";
        changeMessage((std::string) message);
        return;
    } else if (usersController->isSignedIn() == false) {
        char message[] = "please sign in first!\0";
        changeMessage((std::string) message);
        return;
    } else {
        int retVal = 0;
        for(int i = 0; i < ui->serverfiles_list->count(); i++) {
            QListWidgetItem* item = ui->serverfiles_list->item(i);
            if (item->isSelected()) {
//                qDebug("sharefile button: item is ");
//                qDebug(item->text().toStdString().c_str());
                if (-1 == ClientCommandManager::clientCommand->ShareCommand(item->text().toStdString(), ui->friend_lineedit->text().toStdString())) {
                    retVal = -1;
                }
            }
        }
        if (retVal == -1) {
            char message[] = "share file error\0";
            changeMessage((std::string) message);
        }
        if (retVal == 0) {
            char message[] = "share file success!\0";
            changeMessage((std::string) message);
        }
    }
}

void MainWindow::on_refresh_button_clicked()
{
    //then call ls to update the serverfiles_list
  qDebug("before calling lscommand");
    std::set<std::string> filesSet = ClientCommandManager::clientCommand->LsCommand();
    qDebug("after calling lscommand");
    int size = filesSet.size();
    std::set<std::string>::iterator it = filesSet.begin();
    ui->serverfiles_list->clear();
    for (int i=0;i<size;i++){
         std::advance(it, i);
         std::string thisFile = *it;
//         qDebug("iterating through lscommand file list: this item is ");
//         qDebug(thisFile.c_str());
         QString qstr = QString::fromStdString(thisFile);
         ui->serverfiles_list->addItem(qstr);
    }
}

void MainWindow::on_download_button_clicked()
{
    if (ClientCommandManager::clientCommand == NULL) {
        char message[] = "please enter IP first!\0";
        changeMessage((std::string) message);
        return;
    } else if (usersController->isSignedIn() == false) {
        char message[] = "please sign in first!\0";
        changeMessage((std::string) message);
        return;
    } else {
        int retVal = 0;
        for(int i = 0; i < ui->serverfiles_list->count(); i++) {
            QListWidgetItem* item = ui->serverfiles_list->item(i);
            if (item->isSelected()) {
                if (-1 == ClientCommandManager::clientCommand->GetCommand(item->text().toStdString(), "")) {
                    retVal = -1;
                }
            }
        }
        if (retVal == -1) {
            char message[] = "download file error\0";
            changeMessage((std::string) message);
        }
        if (retVal == 0) {
            char message[] = "download success! you can find them in this_program_s_directory/your_username \0";
            changeMessage((std::string) message);
        }
    }
}
