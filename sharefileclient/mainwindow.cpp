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

//void MainWindow::on_cd_button_clicked()
//{
//    if (ClientCommandManager::clientCommand == NULL) {
//        changeMessage("please enter ip first!");
//        return;
//    }
////    else if (signupDialog == NULL) {
////        changeMessage("please enter ip first!");
////        return;
////    } else {
//        std::string path = ui->cd_textedit->toPlainText().toStdString();
//        ClientCommandManager::clientCommand->CdCommand(path) ;
//        //add local files: call the lscommand method in clientcommand, and then add all of them to the list widget
//        ClientCommand * clientCommand = ClientCommandManager::clientCommand;
//        std::set<std::string> filesSet = clientCommand->LsCommand();
//        int size = filesSet.size();
//        std::set<std::string>::iterator it = filesSet.begin();
//        for (int i=0;i<size;i++){
//            std::advance(it, i);
//            std::string thisFile = *it;
//            QString qstr = QString::fromStdString(thisFile);
//            ui->localfiles_list->addItem(qstr);
//        }
////    }
//}

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
    //TODO ADD IP AND SIGNIN WARNINGS

    //when the user selects a file, the path of that file goes into the browse_path_lineedit
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select File"), "/", "All files (*.*)");
    ui->browse_path_lineedit->setText(fileName);
}

bool copyFile(const char *SRC, const char* DEST)
{
    std::ifstream src(SRC, std::ios::binary);
    std::ofstream dest(DEST, std::ios::binary);
    dest << src.rdbuf();
    return src && dest;
}

//std::string get_selfpath() {
//    char buff[1024];
//    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
//    if (len != -1) {
//      buff[len] = '\0';
//      return std::string(buff);
//    } else {
//      std::string empty = "";
//      return empty;
//    }
//}

void MainWindow::on_upload_button_clicked()
{
//    if (ClientCommandManager::clientCommand == NULL) {
//        changeMessage("please enter IP first!");
//        return;
//    } else if (usersController->isSignedIn() == false) {
//        changeMessage("please sign in first");
//        return;
//    } else {

        //TODO first copy the file on the file path to the user's directory
        std::string dest = usersController->getUsername();
        copyFile(ui->browse_path_lineedit->text().toStdString().c_str(), dest.c_str()); //DON'T KNOW IF THIS IS WORKING
        //WHERE IS the user's directory: IT SEEMS IT'S NOT POSSSIBLE TO GET THE PATH
//        std::string path = get_selfpath();
//        perror("the path is \n");
//        perror(path.c_str());

        //then grab the filename of the file (should be in the user's directory) and use the put command
        //then call ls to update the serverfiles_list

//    }
}

void MainWindow::on_sharefile_button_clicked()
{
    //TODO check ip and signed in

    for(int i = 0; i < ui->serverfiles_list->count(); i++) {
        QListWidgetItem* item = serverfiles_list->item(i);
        if (item->isSelected()) {
            ClientCommandManager::clientCommand->ShareCommand(item->text(), ui->friend_lineedit->text());
        }
    }
}
