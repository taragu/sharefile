#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <string>
#include "errorpopup.h"
#include <messagesubject.h>

namespace Ui {
class SignUpDialog;
}

class SignUpDialog : public QDialog, public MessageSubject
{
    Q_OBJECT

public:
    explicit SignUpDialog(QWidget *parent = 0);
    ~SignUpDialog();

private slots:
    void on_signup_submit_accepted();
    void changeMessage(std::string message);
    std::string getMessage();

private:
    Ui::SignUpDialog *ui;
    ErrorPopup * errorPopup;
    std::string message;
};

#endif // SIGNUPDIALOG_H
