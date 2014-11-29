/********************************************************************************
** Form generated from reading UI file 'frienddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDDIALOG_H
#define UI_FRIENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_FriendDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *FriendDialog)
    {
        if (FriendDialog->objectName().isEmpty())
            FriendDialog->setObjectName(QStringLiteral("FriendDialog"));
        FriendDialog->resize(534, 503);
        buttonBox = new QDialogButtonBox(FriendDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(170, 460, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(FriendDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 140, 141, 31));
        label_2 = new QLabel(FriendDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 150, 141, 21));
        textEdit = new QTextEdit(FriendDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(80, 190, 281, 141));
        pushButton = new QPushButton(FriendDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 350, 99, 27));
        pushButton_2 = new QPushButton(FriendDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 460, 141, 21));

        retranslateUi(FriendDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FriendDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FriendDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FriendDialog);
    } // setupUi

    void retranslateUi(QDialog *FriendDialog)
    {
        FriendDialog->setWindowTitle(QApplication::translate("FriendDialog", "Dialog", 0));
        label->setText(QApplication::translate("FriendDialog", "Send a message to ", 0));
        label_2->setText(QApplication::translate("FriendDialog", "(friend's name)", 0));
        pushButton->setText(QApplication::translate("FriendDialog", "Send!", 0));
        pushButton_2->setText(QApplication::translate("FriendDialog", "Unfriend", 0));
    } // retranslateUi

};

namespace Ui {
    class FriendDialog: public Ui_FriendDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDDIALOG_H
