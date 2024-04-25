/********************************************************************************
** Form generated from reading UI file 'changepassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORDDIALOG_H
#define UI_CHANGEPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePasswordDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *letNewP;
    QLineEdit *letOkNewP;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnChange;
    QPushButton *btnCancel;

    void setupUi(QDialog *ChangePasswordDialog)
    {
        if (ChangePasswordDialog->objectName().isEmpty())
            ChangePasswordDialog->setObjectName("ChangePasswordDialog");
        ChangePasswordDialog->resize(400, 300);
        ChangePasswordDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 230, 255);\n"
"\n"
"\n"
""));
        label = new QLabel(ChangePasswordDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(11, 34, 105, 19));
        label_2 = new QLabel(ChangePasswordDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(11, 88, 105, 19));
        letNewP = new QLineEdit(ChangePasswordDialog);
        letNewP->setObjectName("letNewP");
        letNewP->setGeometry(QRect(123, 34, 261, 24));
        letNewP->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"background-color:rgb(237,247,251);\n"
"border-radius:5px;\n"
"font :18px;\n"
"}"));
        letNewP->setEchoMode(QLineEdit::Password);
        letOkNewP = new QLineEdit(ChangePasswordDialog);
        letOkNewP->setObjectName("letOkNewP");
        letOkNewP->setGeometry(QRect(123, 88, 261, 24));
        letOkNewP->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"background-color:rgb(237,247,251);\n"
"border-radius:5px;\n"
"font :18px;\n"
"}"));
        letOkNewP->setEchoMode(QLineEdit::Password);
        widget = new QWidget(ChangePasswordDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(9, 179, 381, 91));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        btnChange = new QPushButton(widget);
        btnChange->setObjectName("btnChange");
        btnChange->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    color: rgb(255, 255, 255);\n"
"background-color: rgb(0,153,255);\n"
"border-radius:5px\n"
"}"));

        horizontalLayout->addWidget(btnChange);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    color: rgb(255, 255, 255);\n"
"background-color: rgb(0,153,255);\n"
"border-radius:5px\n"
"}"));

        horizontalLayout->addWidget(btnCancel);


        retranslateUi(ChangePasswordDialog);

        QMetaObject::connectSlotsByName(ChangePasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangePasswordDialog)
    {
        ChangePasswordDialog->setWindowTitle(QCoreApplication::translate("ChangePasswordDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ChangePasswordDialog", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("ChangePasswordDialog", "\350\257\267\347\241\256\345\256\232\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        btnChange->setText(QCoreApplication::translate("ChangePasswordDialog", "\347\241\256\345\256\232\344\277\256\346\224\271", nullptr));
        btnCancel->setText(QCoreApplication::translate("ChangePasswordDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePasswordDialog: public Ui_ChangePasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORDDIALOG_H
