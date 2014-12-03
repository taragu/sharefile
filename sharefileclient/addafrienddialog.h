#ifndef ADDAFRIENDDIALOG_H
#define ADDAFRIENDDIALOG_H

#include <QDialog>
#include "clientcommandmanager.h"
#include "errorpopup.h"
#include "messagesubject.h"

namespace Ui {
class AddAFriendDialog;
}

class AddAFriendDialog : public QDialog, public MessageSubject
{
    Q_OBJECT

public:
    explicit AddAFriendDialog(QWidget *parent = 0);
    ~AddAFriendDialog();

private slots:
    void on_buttonBox_accepted();
    void changeMessage(std::string string);

    std::string getMessage();

private:
    Ui::AddAFriendDialog *ui;
    ErrorPopup* errorPopup;
    std::string message;
};

#endif // ADDAFRIENDDIALOG_H
