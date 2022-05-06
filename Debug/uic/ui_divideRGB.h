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
    QWidget *scrollAreaWidgetContents;
    QLabel *imgL1;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *imgL2;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *imgL3;

    void setupUi(QWidget *dividergb_class)
    {
        if (dividergb_class->objectName().isEmpty())
            dividergb_class->setObjectName(QString::fromUtf8("dividergb_class"));
        dividergb_class->resize(1610, 552);
        scrollArea = new QScrollArea(dividergb_class);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 20, 512, 512));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 510, 510));
        imgL1 = new QLabel(scrollAreaWidgetContents);
        imgL1->setObjectName(QString::fromUtf8("imgL1"));
        imgL1->setGeometry(QRect(0, 0, 512, 512));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(dividergb_class);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(550, 20, 512, 512));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 510, 510));
        imgL2 = new QLabel(scrollAreaWidgetContents_2);
        imgL2->setObjectName(QString::fromUtf8("imgL2"));
        imgL2->setGeometry(QRect(0, 0, 512, 512));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        scrollArea_3 = new QScrollArea(dividergb_class);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(1080, 20, 512, 512));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 510, 510));
        imgL3 = new QLabel(scrollAreaWidgetContents_3);
        imgL3->setObjectName(QString::fromUtf8("imgL3"));
        imgL3->setGeometry(QRect(0, 0, 512, 512));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

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
