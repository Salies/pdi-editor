/********************************************************************************
** Form generated from reading UI file 'divideRGB.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIVIDERGB_H
#define UI_DIVIDERGB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dividergb_class
{
public:
    QScrollArea *scrollArea;
    QLabel *imgL1;
    QScrollArea *scrollArea_2;
    QLabel *imgL2;
    QScrollArea *scrollArea_3;
    QLabel *imgL3;

    void setupUi(QWidget *dividergb_class)
    {
        if (dividergb_class->objectName().isEmpty())
            dividergb_class->setObjectName(QString::fromUtf8("dividergb_class"));
        dividergb_class->setWindowModality(Qt::ApplicationModal);
        dividergb_class->resize(1616, 554);
        scrollArea = new QScrollArea(dividergb_class);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 20, 514, 514));
        scrollArea->setWidgetResizable(true);
        imgL1 = new QLabel();
        imgL1->setObjectName(QString::fromUtf8("imgL1"));
        imgL1->setGeometry(QRect(0, 0, 512, 512));
        scrollArea->setWidget(imgL1);
        scrollArea_2 = new QScrollArea(dividergb_class);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(552, 20, 514, 514));
        scrollArea_2->setWidgetResizable(true);
        imgL2 = new QLabel();
        imgL2->setObjectName(QString::fromUtf8("imgL2"));
        imgL2->setGeometry(QRect(0, 0, 512, 512));
        scrollArea_2->setWidget(imgL2);
        scrollArea_3 = new QScrollArea(dividergb_class);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(1082, 20, 514, 514));
        scrollArea_3->setWidgetResizable(true);
        imgL3 = new QLabel();
        imgL3->setObjectName(QString::fromUtf8("imgL3"));
        imgL3->setGeometry(QRect(0, 0, 512, 512));
        scrollArea_3->setWidget(imgL3);

        retranslateUi(dividergb_class);

        QMetaObject::connectSlotsByName(dividergb_class);
    } // setupUi

    void retranslateUi(QWidget *dividergb_class)
    {
        dividergb_class->setWindowTitle(QCoreApplication::translate("dividergb_class", "Divis\303\243o em RGB", nullptr));
        imgL1->setText(QString());
        imgL2->setText(QString());
        imgL3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dividergb_class: public Ui_dividergb_class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIVIDERGB_H
