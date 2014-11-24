#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include "errorpopup.h"

namespace Ui {
class SignUpDialog;
}

class SignUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpDialog(QWidget *parent = 0);
    ~SignUpDialog();

private slots:
    void on_signup_submit_accepted();

private:
    Ui::SignUpDialog *ui;
    ErrorPopup * errorPopup;
};

#endif // SIGNUPDIALOG_H
