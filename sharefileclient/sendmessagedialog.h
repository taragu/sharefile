#ifndef SENDMESSAGEDIALOG_H
#define SENDMESSAGEDIALOG_H

#include <QDialog>
#include "errorpopup.h"
#include "messagesubject.h"

namespace Ui {
class SendMessageDialog;
}

class SendMessageDialog : public QDialog, public MessageSubject
{
    Q_OBJECT

public:
    explicit SendMessageDialog(QWidget *parent = 0);
    ~SendMessageDialog();

private slots:
    void on_buttonBox_accepted();

    void on_unfriend_button_clicked();
    void changeMessage(std::string string);

    std::string getMessage();

private:
    Ui::SendMessageDialog *ui;
    ErrorPopup* errorPopup;
    std::string message;
};

#endif // SENDMESSAGEDIALOG_H
