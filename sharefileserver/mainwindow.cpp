#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "servercommand.h"

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

void MainWindow::on_toserver_clicked(bool checked)
{
    ServerCommand::m_port = int(Ui_MainWindow::inputport->);
}
