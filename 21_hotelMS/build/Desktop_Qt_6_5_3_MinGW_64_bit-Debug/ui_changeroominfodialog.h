/********************************************************************************
** Form generated from reading UI file 'changeroominfodialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEROOMINFODIALOG_H
#define UI_CHANGEROOMINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeRoomInfoDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *letRoomNumber;
    QLabel *label_2;
    QLineEdit *letRoomType;
    QLabel *label_3;
    QLineEdit *letRoomDepict;
    QLabel *label_4;
    QLineEdit *letPrice;
    QLabel *label_5;
    QLineEdit *letStatus;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnChange;
    QPushButton *btnCancel;

    void setupUi(QDialog *ChangeRoomInfoDialog)
    {
        if (ChangeRoomInfoDialog->objectName().isEmpty())
            ChangeRoomInfoDialog->setObjectName("ChangeRoomInfoDialog");
        ChangeRoomInfoDialog->resize(400, 300);
        ChangeRoomInfoDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 230, 255);\n"
"\n"
"\n"
""));
        gridLayout = new QGridLayout(ChangeRoomInfoDialog);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(ChangeRoomInfoDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 2);

        letRoomNumber = new QLineEdit(ChangeRoomInfoDialog);
        letRoomNumber->setObjectName("letRoomNumber");
        letRoomNumber->setEnabled(false);

        gridLayout->addWidget(letRoomNumber, 0, 2, 1, 1);

        label_2 = new QLabel(ChangeRoomInfoDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        letRoomType = new QLineEdit(ChangeRoomInfoDialog);
        letRoomType->setObjectName("letRoomType");
        letRoomType->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"background-color:rgb(237,247,251);\n"
"border-radius:5px;\n"
"font :18px;\n"
"}"));

        gridLayout->addWidget(letRoomType, 1, 2, 1, 1);

        label_3 = new QLabel(ChangeRoomInfoDialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        letRoomDepict = new QLineEdit(ChangeRoomInfoDialog);
        letRoomDepict->setObjectName("letRoomDepict");
        letRoomDepict->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"background-color:rgb(237,247,251);\n"
"border-radius:5px;\n"
"font :18px;\n"
"}"));

        gridLayout->addWidget(letRoomDepict, 2, 2, 1, 1);

        label_4 = new QLabel(ChangeRoomInfoDialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        letPrice = new QLineEdit(ChangeRoomInfoDialog);
        letPrice->setObjectName("letPrice");
        letPrice->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"background-color:rgb(237,247,251);\n"
"border-radius:5px;\n"
"font :18px;\n"
"}"));

        gridLayout->addWidget(letPrice, 3, 2, 1, 1);

        label_5 = new QLabel(ChangeRoomInfoDialog);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 2);

        letStatus = new QLineEdit(ChangeRoomInfoDialog);
        letStatus->setObjectName("letStatus");
        letStatus->setEnabled(false);

        gridLayout->addWidget(letStatus, 4, 2, 1, 1);

        widget = new QWidget(ChangeRoomInfoDialog);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"    color: rgb(255, 255, 255);\n"
"background-color: rgb(0,153,255);\n"
"border-radius:5px\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        btnChange = new QPushButton(widget);
        btnChange->setObjectName("btnChange");

        horizontalLayout->addWidget(btnChange);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        gridLayout->addWidget(widget, 5, 0, 1, 3);


        retranslateUi(ChangeRoomInfoDialog);

        QMetaObject::connectSlotsByName(ChangeRoomInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangeRoomInfoDialog)
    {
        ChangeRoomInfoDialog->setWindowTitle(QCoreApplication::translate("ChangeRoomInfoDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ChangeRoomInfoDialog", "\346\210\277\351\227\264\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("ChangeRoomInfoDialog", "\346\210\277\351\227\264\347\261\273\345\236\213", nullptr));
        label_3->setText(QCoreApplication::translate("ChangeRoomInfoDialog", "\346\210\277\351\227\264\346\217\217\350\277\260", nullptr));
        label_4->setText(QCoreApplication::translate("ChangeRoomInfoDialog", "\344\273\267\346\240\274", nullptr));
        label_5->setText(QCoreApplication::translate("ChangeRoomInfoDialog", "\346\210\277\351\227\264\347\212\266\346\200\201", nullptr));
        btnChange->setText(QCoreApplication::translate("ChangeRoomInfoDialog", "\347\241\256\345\256\232\344\277\256\346\224\271", nullptr));
        btnCancel->setText(QCoreApplication::translate("ChangeRoomInfoDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeRoomInfoDialog: public Ui_ChangeRoomInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEROOMINFODIALOG_H
