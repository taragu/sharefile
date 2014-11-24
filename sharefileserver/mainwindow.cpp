#include "mainwindow.h"
#include "servercommand.h"
#include "ui_mainwindow.h"
#include "task.h"

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


void MainWindow::on_toserver_clicked()
{
    Task starter;
        starter.start();

}
