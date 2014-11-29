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

private:
    Ui::ReadMessageDialog *ui;
    bool isARequest;

};

#endif // READMESSAGEDIALOG_H
