/********************************************************************************
** Form generated from reading UI file 'sobelwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOBELWINDOW_H
#define UI_SOBELWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mainlabel.h"

QT_BEGIN_NAMESPACE

class Ui_ui_sobelwindow
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    MainLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *mag;

    void setupUi(QWidget *ui_sobelwindow)
    {
        if (ui_sobelwindow->objectName().isEmpty())
            ui_sobelwindow->setObjectName(QString::fromUtf8("ui_sobelwindow"));
        ui_sobelwindow->setWindowModality(Qt::ApplicationModal);
        ui_sobelwindow->resize(532, 556);
        verticalLayout = new QVBoxLayout(ui_sobelwindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(ui_sobelwindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(514, 514));
        scrollArea->setMaximumSize(QSize(514, 514));
        scrollArea->setWidgetResizable(true);
        label = new MainLabel();
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 512, 512));
        label->setMouseTracking(true);
        scrollArea->setWidget(label);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mag = new QLabel(ui_sobelwindow);
        mag->setObjectName(QString::fromUtf8("mag"));
        QFont font;
        font.setPointSize(10);
        mag->setFont(font);

        horizontalLayout->addWidget(mag);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ui_sobelwindow);

        QMetaObject::connectSlotsByName(ui_sobelwindow);
    } // setupUi

    void retranslateUi(QWidget *ui_sobelwindow)
    {
        ui_sobelwindow->setWindowTitle(QCoreApplication::translate("ui_sobelwindow", "Sobel", nullptr));
        mag->setText(QCoreApplication::translate("ui_sobelwindow", "<html><head/><body><p><span style=\" font-weight:600;\">mag:</span> 0, <span style=\" font-weight:600;\">dir:</span> 0\302\272</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ui_sobelwindow: public Ui_ui_sobelwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOBELWINDOW_H
