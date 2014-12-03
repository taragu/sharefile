#ifndef READMESSAGEDIALOG_H
#define READMESSAGEDIALOG_H

#include <QDialog>
#include "messagesubject.h"
#include "errorpopup.h"

namespace Ui {
class ReadMessageDialog;
}

class ReadMessageDialog : public QDialog, public MessageSubject
{
    Q_OBJECT

public:
    explicit ReadMessageDialog(QWidget *parent = 0);
    ~ReadMessageDialog();
    void setIsARequest(bool _isARequest);
    void setSenderName(std::string username);
    void setMessage(std::string message);

private slots:
    void on_buttonBox_accepted();

    void on_decline_button_clicked();

    void changeMessage(std::string string);

    std::string getMessage();

private:
    Ui::ReadMessageDialog *ui;
    bool isARequest;
    std::string message;
    ErrorPopup * errorPopup;

};

#endif // READMESSAGEDIALOG_H
