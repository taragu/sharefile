#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>
#include <string>
#include "messagesubject.h"
#include "userscontroller.h"

namespace Ui {
class SignInDialog;
}

class SignInDialog : public QDialog, MessageSubject
{
    Q_OBJECT

public:
    explicit SignInDialog(QWidget *parent = 0);
    ~SignInDialog();
    void changeMessage(std::string message);
    std::string getMessage();

private:
    Ui::SignInDialog *ui;
    std::string message;
    ErrorPopup * errorPopup;
};

#endif // SIGNINDIALOG_H
