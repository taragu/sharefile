/********************************************************************************
** Form generated from reading UI file 'addafrienddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDAFRIENDDIALOG_H
#define UI_ADDAFRIENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddAFriendDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *receivername_lineedit;

    void setupUi(QDialog *AddAFriendDialog)
    {
        if (AddAFriendDialog->objectName().isEmpty())
            AddAFriendDialog->setObjectName(QStringLiteral("AddAFriendDialog"));
        AddAFriendDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddAFriendDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AddAFriendDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 100, 161, 41));
        receivername_lineedit = new QLineEdit(AddAFriendDialog);
        receivername_lineedit->setObjectName(QStringLiteral("receivername_lineedit"));
        receivername_lineedit->setGeometry(QRect(190, 110, 181, 31));

        retranslateUi(AddAFriendDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddAFriendDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddAFriendDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddAFriendDialog);
    } // setupUi

    void retranslateUi(QDialog *AddAFriendDialog)
    {
        AddAFriendDialog->setWindowTitle(QApplication::translate("AddAFriendDialog", "Dialog", 0));
        label->setText(QApplication::translate("AddAFriendDialog", "Friend's username", 0));
    } // retranslateUi

};

namespace Ui {
    class AddAFriendDialog: public Ui_AddAFriendDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDAFRIENDDIALOG_H
