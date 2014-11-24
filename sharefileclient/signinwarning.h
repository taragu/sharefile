#ifndef SIGNINWARNING_H
#define SIGNINWARNING_H

#include <QDialog>

namespace Ui {
class SigninWarning;
}

class SigninWarning : public QDialog
{
    Q_OBJECT

public:
    explicit SigninWarning(QWidget *parent = 0);
    ~SigninWarning();

private:
    Ui::SigninWarning *ui;
};

#endif // SIGNINWARNING_H
