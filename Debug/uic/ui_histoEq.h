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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_histoEq
{
public:
    QwtPlot *histoPlot;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *spinBox_3;
    QLabel *label_7;
    QSpinBox *spinBox_4;
    QPushButton *pushButton;

    void setupUi(QWidget *histoEq)
    {
        if (histoEq->objectName().isEmpty())
            histoEq->setObjectName(QString::fromUtf8("histoEq"));
        histoEq->setWindowModality(Qt::ApplicationModal);
        histoEq->resize(280, 274);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(histoEq->sizePolicy().hasHeightForWidth());
        histoEq->setSizePolicy(sizePolicy);
        histoEq->setMinimumSize(QSize(280, 274));
        histoEq->setMaximumSize(QSize(280, 274));
        histoPlot = new QwtPlot(histoEq);
        histoPlot->setObjectName(QString::fromUtf8("histoPlot"));
        histoPlot->setGeometry(QRect(20, 20, 240, 130));
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        histoPlot->setCanvasBackground(brush);
        horizontalLayoutWidget = new QWidget(histoEq);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 180, 261, 22));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        spinBox = new QSpinBox(horizontalLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        spinBox_2 = new QSpinBox(horizontalLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout->addWidget(spinBox_2);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(2, 10);
        horizontalLayout->setStretch(3, 5);
        horizontalLayout->setStretch(4, 10);
        label = new QLabel(histoEq);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 160, 111, 20));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        horizontalLayoutWidget_2 = new QWidget(histoEq);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 210, 261, 22));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        spinBox_3 = new QSpinBox(horizontalLayoutWidget_2);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        horizontalLayout_2->addWidget(spinBox_3);

        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_7);

        spinBox_4 = new QSpinBox(horizontalLayoutWidget_2);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));

        horizontalLayout_2->addWidget(spinBox_4);

        horizontalLayout_2->setStretch(0, 10);
        horizontalLayout_2->setStretch(2, 10);
        horizontalLayout_2->setStretch(3, 5);
        horizontalLayout_2->setStretch(4, 10);
        pushButton = new QPushButton(histoEq);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 240, 260, 24));

        retranslateUi(histoEq);

        QMetaObject::connectSlotsByName(histoEq);
    } // setupUi

    void retranslateUi(QWidget *histoEq)
    {
        histoEq->setWindowTitle(QCoreApplication::translate("histoEq", "Equalizar histograma", nullptr));
        label_2->setText(QCoreApplication::translate("histoEq", "Largura", nullptr));
        label_4->setText(QCoreApplication::translate("histoEq", "de", nullptr));
        label_3->setText(QCoreApplication::translate("histoEq", "at\303\251", nullptr));
        label->setText(QCoreApplication::translate("histoEq", "Equalizar trecho", nullptr));
        label_5->setText(QCoreApplication::translate("histoEq", "Altura", nullptr));
        label_6->setText(QCoreApplication::translate("histoEq", "de", nullptr));
        label_7->setText(QCoreApplication::translate("histoEq", "at\303\251", nullptr));
        pushButton->setText(QCoreApplication::translate("histoEq", "Equalizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class histoEq: public Ui_histoEq {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOEQ_H
