#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signupdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




//move local files to server
void MainWindow::on_movefiles_button_clicked()
{

}
//open the signup widget
void MainWindow::on_signup_button_clicked()
{
    SignUpDialog signup;
    signup.setModal(true);
    signup.exec();
}
