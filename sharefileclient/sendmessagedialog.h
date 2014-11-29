#ifndef SENDMESSAGEDIALOG_H
#define SENDMESSAGEDIALOG_H

#include <QDialog>

namespace Ui {
class SendMessageDialog;
}

class SendMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SendMessageDialog(QWidget *parent = 0);
    ~SendMessageDialog();

private:
    Ui::SendMessageDialog *ui;
};

#endif // SENDMESSAGEDIALOG_H
