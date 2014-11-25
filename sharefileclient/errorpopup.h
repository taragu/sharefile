#ifndef ERRORPOPUP_H
#define ERRORPOPUP_H

#include <QDialog>
#include <IObserver.h>

namespace Ui {
class ErrorPopup;
}

class ErrorPopup : public QDialog, IObserver
{
    Q_OBJECT

public:
    explicit ErrorPopup(QWidget *parent = 0);
    virtual void update(std::string message);
    ~ErrorPopup();

private:
    Ui::ErrorPopup *ui;
    std::string message;
};

#endif // ERRORPOPUP_H
