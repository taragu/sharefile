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
    void setError(std::string);
    ~ErrorPopup();

private:
    Ui::ErrorPopup *ui;
};

#endif // ERRORPOPUP_H
