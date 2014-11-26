#ifndef FRIENDREQUESTPOPUP_H
#define FRIENDREQUESTPOPUP_H

#include <QDialog>
#include "errorpopup.h"

namespace Ui {
class FriendRequestPopup;
}

class FriendRequestPopup : public virtual QDialog, public virtual ErrorPopup
{
    Q_OBJECT

public:
    explicit FriendRequestPopup(QWidget *parent = 0);
    ~FriendRequestPopup();
    virtual void update(std::string friendName);

private:
    Ui::FriendRequestPopup *ui;
    std::string friendName;
};

#endif // FRIENDREQUESTPOPUP_H
