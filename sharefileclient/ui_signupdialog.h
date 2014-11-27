/********************************************************************************
** Form generated from reading UI file 'signupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDIALOG_H
#define UI_SIGNUPDIALOG_H

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

class Ui_SignUpDialog
{
public:
    QDialogButtonBox *signup_submit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *signup_username_textedit;
    QLineEdit *signup_password_textedit;
    QLineEdit *signup_passwordconf_textedit;

    void setupUi(QDialog *SignUpDialog)
    {
        if (SignUpDialog->objectName().isEmpty())
            SignUpDialog->setObjectName(QStringLiteral("SignUpDialog"));
        SignUpDialog->resize(400, 300);
        signup_submit = new QDialogButtonBox(SignUpDialog);
        signup_submit->setObjectName(QStringLiteral("signup_submit"));
        signup_submit->setGeometry(QRect(30, 240, 341, 32));
        signup_submit->setOrientation(Qt::Horizontal);
        signup_submit->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SignUpDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 111, 21));
        label_2 = new QLabel(SignUpDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 100, 81, 17));
        label_3 = new QLabel(SignUpDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 130, 81, 20));
        label_4 = new QLabel(SignUpDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 170, 171, 21));
        signup_username_textedit = new QLineEdit(SignUpDialog);
        signup_username_textedit->setObjectName(QStringLiteral("signup_username_textedit"));
        signup_username_textedit->setGeometry(QRect(170, 90, 113, 27));
        signup_password_textedit = new QLineEdit(SignUpDialog);
        signup_password_textedit->setObjectName(QStringLiteral("signup_password_textedit"));
        signup_password_textedit->setGeometry(QRect(170, 130, 113, 27));
        signup_password_textedit->setEchoMode(QLineEdit::Password);
        signup_passwordconf_textedit = new QLineEdit(SignUpDialog);
        signup_passwordconf_textedit->setObjectName(QStringLiteral("signup_passwordconf_textedit"));
        signup_passwordconf_textedit->setGeometry(QRect(190, 170, 113, 27));
        signup_passwordconf_textedit->setEchoMode(QLineEdit::Password);

        retranslateUi(SignUpDialog);
        QObject::connect(signup_submit, SIGNAL(accepted()), SignUpDialog, SLOT(accept()));
        QObject::connect(signup_submit, SIGNAL(rejected()), SignUpDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SignUpDialog);
    } // setupUi

    void retranslateUi(QDialog *SignUpDialog)
    {
        SignUpDialog->setWindowTitle(QApplication::translate("SignUpDialog", "Dialog", 0));
        label->setText(QApplication::translate("SignUpDialog", "Signup Form", 0));
        label_2->setText(QApplication::translate("SignUpDialog", "Username", 0));
        label_3->setText(QApplication::translate("SignUpDialog", "Password", 0));
        label_4->setText(QApplication::translate("SignUpDialog", "Password Confirmation", 0));
    } // retranslateUi

};

namespace Ui {
    class SignUpDialog: public Ui_SignUpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDIALOG_H
