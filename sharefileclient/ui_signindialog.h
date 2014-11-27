/********************************************************************************
** Form generated from reading UI file 'signindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINDIALOG_H
#define UI_SIGNINDIALOG_H

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

class Ui_SignInDialog
{
public:
    QDialogButtonBox *signin_submit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *signin_username_textedit;
    QLineEdit *signin_password_textedit;

    void setupUi(QDialog *SignInDialog)
    {
        if (SignInDialog->objectName().isEmpty())
            SignInDialog->setObjectName(QStringLiteral("SignInDialog"));
        SignInDialog->resize(529, 453);
        signin_submit = new QDialogButtonBox(SignInDialog);
        signin_submit->setObjectName(QStringLiteral("signin_submit"));
        signin_submit->setGeometry(QRect(150, 400, 341, 32));
        signin_submit->setOrientation(Qt::Horizontal);
        signin_submit->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SignInDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 100, 131, 31));
        label_2 = new QLabel(SignInDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 160, 91, 16));
        label_3 = new QLabel(SignInDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 190, 67, 17));
        signin_username_textedit = new QLineEdit(SignInDialog);
        signin_username_textedit->setObjectName(QStringLiteral("signin_username_textedit"));
        signin_username_textedit->setGeometry(QRect(200, 150, 113, 27));
        signin_password_textedit = new QLineEdit(SignInDialog);
        signin_password_textedit->setObjectName(QStringLiteral("signin_password_textedit"));
        signin_password_textedit->setGeometry(QRect(200, 180, 113, 27));
        signin_password_textedit->setEchoMode(QLineEdit::Password);

        retranslateUi(SignInDialog);
        QObject::connect(signin_submit, SIGNAL(accepted()), SignInDialog, SLOT(accept()));
        QObject::connect(signin_submit, SIGNAL(rejected()), SignInDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SignInDialog);
    } // setupUi

    void retranslateUi(QDialog *SignInDialog)
    {
        SignInDialog->setWindowTitle(QApplication::translate("SignInDialog", "Dialog", 0));
        label->setText(QApplication::translate("SignInDialog", "Signin Form", 0));
        label_2->setText(QApplication::translate("SignInDialog", "Username", 0));
        label_3->setText(QApplication::translate("SignInDialog", "Password", 0));
    } // retranslateUi

};

namespace Ui {
    class SignInDialog: public Ui_SignInDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINDIALOG_H
