#ifndef READMESSAGEDIALOG_H
#define READMESSAGEDIALOG_H

#include <QDialog>

namespace Ui {
class ReadMessageDialog;
}

class ReadMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReadMessageDialog(QWidget *parent = 0);
    ~ReadMessageDialog();
    void setIsARequest(bool _isARequest);

private slots:
    void on_buttonBox_accepted();

    void on_decline_button_clicked();

private:
    Ui::ReadMessageDialog *ui;
    bool isARequest;

};

#endif // READMESSAGEDIALOG_H
