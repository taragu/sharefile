#ifndef ADDAFRIENDDIALOG_H
#define ADDAFRIENDDIALOG_H

#include <QDialog>

namespace Ui {
class AddAFriendDialog;
}

class AddAFriendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAFriendDialog(QWidget *parent = 0);
    ~AddAFriendDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddAFriendDialog *ui;
};

#endif // ADDAFRIENDDIALOG_H
