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
    attach(friendRequest);
}

void MainWindow::destroyAll(){
    delete ui;
    delete signupDialog;
    delete signinDialog;
    delete errorPopup;
    delete friendRequest;
    delete usersController;
}

MainWindow::~MainWindow()
{
    destroyAll();
}

void MainWindow::on_signup_button_clicked()
{
    qDebug("signup botton clicked\n");
    if (ClientCommandManager::clientCommand == NULL) {
        changeMessage("please enter ip first!");
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
        changeMessage("please enter ip first!");
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
        changeMessage("please enter IP first!");
        return;
    } else if (usersController->isSignedIn() == false) {
        changeMessage("please sign in first");
        return;
    } else {
        addAFriendDialog->setModal(true);
        addAFriendDialog->exec();
    }
}

void MainWindow::on_browse_button_clicked()
{
    if (ClientCommandManager::clientCommand == NULL) {
        changeMessage("please enter IP first!");
        return;
    } else if (usersController->isSignedIn() == false) {
        changeMessage("please sign in first");
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
        changeMessage("please enter IP first!");
        return;
    } else if (usersController->isSignedIn() == false) {
        changeMessage("please sign in first");
        return;
    } else {
        //first copy the file on the file path to the user's directory
        std::string currentPath = QDir::currentPath().toStdString();
        std::string dest = currentPath + "/" + usersController->getUsername();
        std::string source_filepath = ui->browse_path_lineedit->text().toStdString();
        std::vector<std::string> seglist = split(source_filepath, '/');
        std::string fileName = seglist[seglist.size()-1];
        std::string dest_filepath = dest + "/"+ fileName;
//        qDebug(source_filepath.c_str());
//        qDebug(dest_filepath.c_str());
        QFile::copy(QString::fromStdString(source_filepath), QString::fromStdString(dest_filepath));
        //then grab the filename of the file (should be in the user's directory) and use the put command
        ClientCommandManager::clientCommand->PutCommand(fileName);
        //then call ls to update the serverfiles_list: TODO PICK UP HERE TOMORROW
        std::set<std::string> filesSet = ClientCommandManager::clientCommand->LsCommand();
        int size = filesSet.size();
        std::set<std::string>::iterator it = filesSet.begin();
        for (int i=0;i<size;i++){
             std::advance(it, i);
             std::string thisFile = *it;
             QString qstr = QString::fromStdString(thisFile);
             ui->serverfiles_list->addItem(qstr);
        }
    }
}

void MainWindow::on_sharefile_button_clicked()
{
    if (ClientCommandManager::clientCommand == NULL) {
        changeMessage("please enter IP first!");
        return;
    } else if (usersController->isSignedIn() == false) {
        changeMessage("please sign in first");
        return;
    } else {
        for(int i = 0; i < ui->serverfiles_list->count(); i++) {
            QListWidgetItem* item = ui->serverfiles_list->item(i);
            if (item->isSelected()) {
                ClientCommandManager::clientCommand->ShareCommand(item->text().toStdString(), ui->friend_lineedit->text().toStdString());
            }
        }
    }
}
