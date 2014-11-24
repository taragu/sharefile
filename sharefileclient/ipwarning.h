#ifndef IPWARNING_H
#define IPWARNING_H

#include <QDialog>

namespace Ui {
class IPWarning;
}

class IPWarning : public QDialog
{
    Q_OBJECT

public:
    explicit IPWarning(QWidget *parent = 0);
    ~IPWarning();

private:
    Ui::IPWarning *ui;
};

#endif // IPWARNING_H
