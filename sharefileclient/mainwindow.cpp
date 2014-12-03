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
    addAFriendDialog = new AddAFriendDialog();
    signupDialog = new SignUpDialog();
    signinDialog = new SignInDialog();
    sendMessageDialog = new SendMessageDialog();
    readMessageDialog = new ReadMessageDialog();
    attach(errorPopup); //IMPORTANT!!! observer pattern
}

void MainWindow::destroyAll(){
    delete ui;
    delete signupDialog;
    delete signinDialog;
    delete errorPopup;
    delete usersController;
    delete addAFriendDialog;
    delete sendMessageDialog;
    delete readMessageDialog;
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
    } else if (ui->friend_lineedit->text().isEmpty()){
        char message[] = "please enter your friend's name!\0";
        changeMessage((std::string) message);
        return;
    } else {
        int retVal = 0;
        for(int i = 0; i < ui->serverfiles_list->count(); i++) {
            QListWidgetItem* item = ui->serverfiles_list->item(i);
            if (item->isSelected()) {
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

void MainWindow::refresh_serverfiles_list() {
    std::set<std::string> filesSet = ClientCommandManager::clientCommand->LsCommand();
    int size = filesSet.size();
    std::set<std::string>::iterator it = filesSet.begin();
    ui->serverfiles_list->clear();
    for (int i=0;i<size;i++){
         std::advance(it, i);
         std::string thisFile = *it;
         QString qstr = QString::fromStdString(thisFile);
         ui->serverfiles_list->addItem(qstr);
    }
}

void MainWindow::refresh_messages_list() {
    // CALL LISTMESSAGES METHOD FROM CLIENTCOMMAND
    std::set<std::string> messagesSet = ClientCommandManager::clientCommand->LsmCommand();
    int size = messagesSet.size();
    std::set<std::string>::iterator it = messagesSet.begin();
    ui->messages_list->clear();
    for (int i=0;i<size;i++){
         std::advance(it, i);
         std::string thisMessage = *it;
         QString qstr = QString::fromStdString(thisMessage);
         ui->messages_list->addItem(qstr);
    }
}

void MainWindow::refresh_friends_list() {
    // CALL LISTFRIENDS METHOD FROM CLIENTCOMMAND
    std::set<std::string> friendsSet = ClientCommandManager::clientCommand->LsfCommand();
    int size = friendsSet.size();
    std::set<std::string>::iterator it = friendsSet.begin();
    ui->friends_list->clear();
    for (int i=0;i<size;i++){
         std::advance(it, i);
         std::string thisFriend = *it;
         QString qstr = QString::fromStdString(thisFriend);
         ui->friends_list->addItem(qstr);
    }
}

void MainWindow::on_refresh_button_clicked()
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
        refresh_serverfiles_list();
        refresh_messages_list();
        refresh_friends_list();
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

void MainWindow::on_delete_button_clicked()
{
    //delete selected files
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
                if (-1 == ClientCommandManager::clientCommand->RmCommand(item->text().toStdString())) {
                    retVal = -1;
                }
            }
        }
        if (retVal == -1) {
            char message[] = "remove file error\0";
            changeMessage((std::string) message);
        }
        if (retVal == 0) {
            char message[] = "remove success!\0";
            changeMessage((std::string) message);
        }
    }
}

void MainWindow::on_messages_list_itemClicked(QListWidgetItem *item)
{
    QByteArray itemByteArray = item->text().toUtf8();
    char* itemArray = itemByteArray.data();
    char * openParenthesis = strchr(itemArray, '(');
    int openIndex = openParenthesis - itemArray + 1;
    char * closeParenthesis = strchr(itemArray, ')');
    int closeIndex = closeParenthesis - itemArray + 1;
    //grab the sender's name and the message
    std::string itemString = (std::string) itemArray;
    std::string senderName = itemString.substr(openIndex, closeIndex - openIndex - 1);
    std::string message = itemString.substr(closeIndex+1);
    //check if the item is a regular message or a request
    if (message == "friend") {
        readMessageDialog->setIsARequest(true);
    }
    readMessageDialog->setSenderName(senderName);
    readMessageDialog->setModal(true);
    readMessageDialog->exec();
}

void MainWindow::on_friends_list_itemClicked(QListWidgetItem *item)
{
    QByteArray friendNameByteArray = item->text().toUtf8();
    const char* friendName = friendNameByteArray.constData();
    sendMessageDialog->setReceiver((std::string)friendName);
    sendMessageDialog->setModal(true);
    sendMessageDialog->exec();
}

void MainWindow::on_test_send_button_clicked()
{
    sendMessageDialog->setModal(true);
    sendMessageDialog->exec();
}
