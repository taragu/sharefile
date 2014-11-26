#ifndef FRIENDDIALOG_H
#define FRIENDDIALOG_H

#include <QDialog>

namespace Ui {
class FriendDialog;
}

class FriendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FriendDialog(QWidget *parent = 0);
    ~FriendDialog();

private:
    Ui::FriendDialog *ui;
};

#endif // FRIENDDIALOG_H
