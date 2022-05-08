/********************************************************************************
** Form generated from reading UI file 'histoEq.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOEQ_H
#define UI_HISTOEQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_histoEq
{
public:
    QwtPlot *histoPlot;
    QPushButton *pushButton;

    void setupUi(QWidget *histoEq)
    {
        if (histoEq->objectName().isEmpty())
            histoEq->setObjectName(QString::fromUtf8("histoEq"));
        histoEq->setWindowModality(Qt::ApplicationModal);
        histoEq->resize(280, 190);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(histoEq->sizePolicy().hasHeightForWidth());
        histoEq->setSizePolicy(sizePolicy);
        histoEq->setMinimumSize(QSize(280, 190));
        histoEq->setMaximumSize(QSize(280, 190));
        histoPlot = new QwtPlot(histoEq);
        histoPlot->setObjectName(QString::fromUtf8("histoPlot"));
        histoPlot->setGeometry(QRect(20, 20, 240, 130));
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        histoPlot->setCanvasBackground(brush);
        pushButton = new QPushButton(histoEq);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 160, 260, 24));

        retranslateUi(histoEq);

        QMetaObject::connectSlotsByName(histoEq);
    } // setupUi

    void retranslateUi(QWidget *histoEq)
    {
        histoEq->setWindowTitle(QCoreApplication::translate("histoEq", "Equalizar histograma", nullptr));
        pushButton->setText(QCoreApplication::translate("histoEq", "Equalizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class histoEq: public Ui_histoEq {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOEQ_H
