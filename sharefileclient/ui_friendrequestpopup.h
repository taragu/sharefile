/********************************************************************************
** Form generated from reading UI file 'friendrequestpopup.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDREQUESTPOPUP_H
#define UI_FRIENDREQUESTPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FriendRequestPopup
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *friendName_label;
    QLabel *label_2;

    void setupUi(QDialog *FriendRequestPopup)
    {
        if (FriendRequestPopup->objectName().isEmpty())
            FriendRequestPopup->setObjectName(QStringLiteral("FriendRequestPopup"));
        FriendRequestPopup->resize(400, 300);
        pushButton = new QPushButton(FriendRequestPopup);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 210, 99, 27));
        pushButton_2 = new QPushButton(FriendRequestPopup);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 210, 99, 27));
        friendName_label = new QLabel(FriendRequestPopup);
        friendName_label->setObjectName(QStringLiteral("friendName_label"));
        friendName_label->setGeometry(QRect(80, 120, 161, 21));
        label_2 = new QLabel(FriendRequestPopup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 150, 201, 21));

        retranslateUi(FriendRequestPopup);

        QMetaObject::connectSlotsByName(FriendRequestPopup);
    } // setupUi

    void retranslateUi(QDialog *FriendRequestPopup)
    {
        FriendRequestPopup->setWindowTitle(QApplication::translate("FriendRequestPopup", "Dialog", 0));
        pushButton->setText(QApplication::translate("FriendRequestPopup", "Accept", 0));
        pushButton_2->setText(QApplication::translate("FriendRequestPopup", "Decline", 0));
        friendName_label->setText(QApplication::translate("FriendRequestPopup", "(friend's name)", 0));
        label_2->setText(QApplication::translate("FriendRequestPopup", "wants to be your friend!", 0));
    } // retranslateUi

};

namespace Ui {
    class FriendRequestPopup: public Ui_FriendRequestPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDREQUESTPOPUP_H
