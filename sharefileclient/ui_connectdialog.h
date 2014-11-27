/********************************************************************************
** Form generated from reading UI file 'connectdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ConnectDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *ip_textedit;
    QLineEdit *portnumber_textedit;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QString::fromUtf8("ConnectDialog"));
        ConnectDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(ConnectDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ConnectDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 80, 67, 17));
        label_2 = new QLabel(ConnectDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(56, 140, 91, 20));
        ip_textedit = new QLineEdit(ConnectDialog);
        ip_textedit->setObjectName(QString::fromUtf8("ip_textedit"));
        ip_textedit->setGeometry(QRect(150, 70, 191, 31));
        portnumber_textedit = new QLineEdit(ConnectDialog);
        portnumber_textedit->setObjectName(QString::fromUtf8("portnumber_textedit"));
        portnumber_textedit->setGeometry(QRect(170, 140, 113, 27));

        retranslateUi(ConnectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QApplication::translate("ConnectDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConnectDialog", "IP", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConnectDialog", "Port Number", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
