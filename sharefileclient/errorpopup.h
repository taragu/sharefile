#ifndef ERRORPOPUP_H
#define ERRORPOPUP_H

#include <QDialog>

namespace Ui {
class ErrorPopup;
}

class ErrorPopup : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorPopup(QWidget *parent = 0);
    Ui::ErrorPopup * getUI();
    ~ErrorPopup();

private:
    Ui::ErrorPopup *ui;
};

#endif // ERRORPOPUP_H
