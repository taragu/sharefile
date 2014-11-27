/********************************************************************************
** Form generated from reading UI file 'errorpopup.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORPOPUP_H
#define UI_ERRORPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ErrorPopup
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *errormsg_label;

    void setupUi(QDialog *ErrorPopup)
    {
        if (ErrorPopup->objectName().isEmpty())
            ErrorPopup->setObjectName(QStringLiteral("ErrorPopup"));
        ErrorPopup->resize(586, 429);
        buttonBox = new QDialogButtonBox(ErrorPopup);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(220, 380, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        errormsg_label = new QLabel(ErrorPopup);
        errormsg_label->setObjectName(QStringLiteral("errormsg_label"));
        errormsg_label->setGeometry(QRect(50, 80, 481, 241));

        retranslateUi(ErrorPopup);
        QObject::connect(buttonBox, SIGNAL(accepted()), ErrorPopup, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ErrorPopup, SLOT(reject()));

        QMetaObject::connectSlotsByName(ErrorPopup);
    } // setupUi

    void retranslateUi(QDialog *ErrorPopup)
    {
        ErrorPopup->setWindowTitle(QApplication::translate("ErrorPopup", "Dialog", 0));
        errormsg_label->setText(QApplication::translate("ErrorPopup", "(Display error message in this label)", 0));
    } // retranslateUi

};

namespace Ui {
    class ErrorPopup: public Ui_ErrorPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORPOPUP_H
