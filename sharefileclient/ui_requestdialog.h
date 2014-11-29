/********************************************************************************
** Form generated from reading UI file 'requestdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUESTDIALOG_H
#define UI_REQUESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_RequestDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLabel *sendername_lineedit;
    QLabel *label;
    QLabel *message_label;

    void setupUi(QDialog *RequestDialog)
    {
        if (RequestDialog->objectName().isEmpty())
            RequestDialog->setObjectName(QStringLiteral("RequestDialog"));
        RequestDialog->resize(599, 452);
        buttonBox = new QDialogButtonBox(RequestDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(220, 380, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_2 = new QLabel(RequestDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 100, 67, 17));
        sendername_lineedit = new QLabel(RequestDialog);
        sendername_lineedit->setObjectName(QStringLiteral("sendername_lineedit"));
        sendername_lineedit->setGeometry(QRect(130, 60, 251, 16));
        label = new QLabel(RequestDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 60, 67, 17));
        message_label = new QLabel(RequestDialog);
        message_label->setObjectName(QStringLiteral("message_label"));
        message_label->setGeometry(QRect(150, 100, 311, 211));
        message_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        message_label->setWordWrap(true);

        retranslateUi(RequestDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RequestDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RequestDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RequestDialog);
    } // setupUi

    void retranslateUi(QDialog *RequestDialog)
    {
        RequestDialog->setWindowTitle(QApplication::translate("RequestDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("RequestDialog", "Message", 0));
        sendername_lineedit->setText(QApplication::translate("RequestDialog", "(display sender's name here)", 0));
        label->setText(QApplication::translate("RequestDialog", "Sender", 0));
        message_label->setText(QApplication::translate("RequestDialog", "I want to be your friend.", 0));
    } // retranslateUi

};

namespace Ui {
    class RequestDialog: public Ui_RequestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTDIALOG_H
