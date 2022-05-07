/********************************************************************************
** Form generated from reading UI file 'conv_hsl.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONV_HSL_H
#define UI_CONV_HSL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_conv_hsl_class
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QSpinBox *spinS;
    QSpinBox *spinR;
    QLabel *label_2;
    QSpinBox *spinL;
    QSpinBox *spinG;
    QLabel *label_5;
    QSpinBox *spinB;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_4;
    QSpinBox *spinH;
    QPushButton *buttonToHSL;
    QPushButton *buttonToRGB;

    void setupUi(QWidget *conv_hsl_class)
    {
        if (conv_hsl_class->objectName().isEmpty())
            conv_hsl_class->setObjectName(QString::fromUtf8("conv_hsl_class"));
        conv_hsl_class->resize(250, 203);
        gridLayoutWidget = new QWidget(conv_hsl_class);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 231, 191));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1, Qt::AlignRight);

        spinS = new QSpinBox(gridLayoutWidget);
        spinS->setObjectName(QString::fromUtf8("spinS"));
        spinS->setMaximum(240);

        gridLayout->addWidget(spinS, 1, 3, 1, 1);

        spinR = new QSpinBox(gridLayoutWidget);
        spinR->setObjectName(QString::fromUtf8("spinR"));
        spinR->setMaximum(255);

        gridLayout->addWidget(spinR, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1, Qt::AlignRight);

        spinL = new QSpinBox(gridLayoutWidget);
        spinL->setObjectName(QString::fromUtf8("spinL"));
        spinL->setMaximum(240);

        gridLayout->addWidget(spinL, 2, 3, 1, 1);

        spinG = new QSpinBox(gridLayoutWidget);
        spinG->setObjectName(QString::fromUtf8("spinG"));
        spinG->setMaximum(255);

        gridLayout->addWidget(spinG, 1, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 1, 2, 1, 1, Qt::AlignRight);

        spinB = new QSpinBox(gridLayoutWidget);
        spinB->setObjectName(QString::fromUtf8("spinB"));
        spinB->setMaximum(255);

        gridLayout->addWidget(spinB, 2, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setScaledContents(false);
        label->setWordWrap(false);

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignRight);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 2, 2, 1, 1, Qt::AlignRight);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 2, 1, 1, Qt::AlignRight);

        spinH = new QSpinBox(gridLayoutWidget);
        spinH->setObjectName(QString::fromUtf8("spinH"));
        spinH->setMaximum(239);

        gridLayout->addWidget(spinH, 0, 3, 1, 1);

        buttonToHSL = new QPushButton(gridLayoutWidget);
        buttonToHSL->setObjectName(QString::fromUtf8("buttonToHSL"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonToHSL->sizePolicy().hasHeightForWidth());
        buttonToHSL->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(buttonToHSL, 3, 0, 1, 2);

        buttonToRGB = new QPushButton(gridLayoutWidget);
        buttonToRGB->setObjectName(QString::fromUtf8("buttonToRGB"));

        gridLayout->addWidget(buttonToRGB, 3, 2, 1, 2);

        gridLayout->setColumnStretch(0, 10);
        gridLayout->setColumnStretch(1, 20);
        gridLayout->setColumnStretch(2, 10);
        gridLayout->setColumnStretch(3, 20);

        retranslateUi(conv_hsl_class);

        QMetaObject::connectSlotsByName(conv_hsl_class);
    } // setupUi

    void retranslateUi(QWidget *conv_hsl_class)
    {
        conv_hsl_class->setWindowTitle(QCoreApplication::translate("conv_hsl_class", "Convers\303\243o RGB/HSL", nullptr));
        label_3->setText(QCoreApplication::translate("conv_hsl_class", "B", nullptr));
        label_2->setText(QCoreApplication::translate("conv_hsl_class", "G", nullptr));
        label_5->setText(QCoreApplication::translate("conv_hsl_class", "S", nullptr));
        label->setText(QCoreApplication::translate("conv_hsl_class", "R", nullptr));
        label_6->setText(QCoreApplication::translate("conv_hsl_class", "L", nullptr));
        label_4->setText(QCoreApplication::translate("conv_hsl_class", "H", nullptr));
        buttonToHSL->setText(QCoreApplication::translate("conv_hsl_class", "Converter para\n"
"HSL", nullptr));
        buttonToRGB->setText(QCoreApplication::translate("conv_hsl_class", "Converter para\n"
"RGB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class conv_hsl_class: public Ui_conv_hsl_class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONV_HSL_H
