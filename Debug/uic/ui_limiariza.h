/********************************************************************************
** Form generated from reading UI file 'limiariza.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIMIARIZA_H
#define UI_LIMIARIZA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ui_lim
{
public:
    QVBoxLayout *verticalLayout;
    QSpinBox *spinBox;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ui_lim)
    {
        if (ui_lim->objectName().isEmpty())
            ui_lim->setObjectName(QString::fromUtf8("ui_lim"));
        ui_lim->setWindowModality(Qt::ApplicationModal);
        ui_lim->resize(152, 77);
        verticalLayout = new QVBoxLayout(ui_lim);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        spinBox = new QSpinBox(ui_lim);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(255);

        verticalLayout->addWidget(spinBox);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(ui_lim);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setMaximumSize(QSize(60, 16777215));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(ui_lim);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMaximumSize(QSize(60, 16777215));

        hboxLayout->addWidget(cancelButton);


        verticalLayout->addLayout(hboxLayout);


        retranslateUi(ui_lim);
        QObject::connect(okButton, SIGNAL(clicked()), ui_lim, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), ui_lim, SLOT(reject()));

        QMetaObject::connectSlotsByName(ui_lim);
    } // setupUi

    void retranslateUi(QDialog *ui_lim)
    {
        ui_lim->setWindowTitle(QCoreApplication::translate("ui_lim", "Limiariza\303\247\303\243o", nullptr));
        okButton->setText(QCoreApplication::translate("ui_lim", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("ui_lim", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ui_lim: public Ui_ui_lim {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIMIARIZA_H
