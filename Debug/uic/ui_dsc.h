/********************************************************************************
** Form generated from reading UI file 'dsc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSC_H
#define UI_DSC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dsc_ui
{
public:
    QLabel *label;
    QDoubleSpinBox *cSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *gSpinBox;
    QPushButton *okButton;

    void setupUi(QWidget *dsc_ui)
    {
        if (dsc_ui->objectName().isEmpty())
            dsc_ui->setObjectName(QString::fromUtf8("dsc_ui"));
        dsc_ui->resize(200, 68);
        label = new QLabel(dsc_ui);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 16, 21));
        cSpinBox = new QDoubleSpinBox(dsc_ui);
        cSpinBox->setObjectName(QString::fromUtf8("cSpinBox"));
        cSpinBox->setGeometry(QRect(30, 10, 62, 22));
        label_2 = new QLabel(dsc_ui);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 10, 16, 21));
        label_2->setLayoutDirection(Qt::LeftToRight);
        gSpinBox = new QDoubleSpinBox(dsc_ui);
        gSpinBox->setObjectName(QString::fromUtf8("gSpinBox"));
        gSpinBox->setGeometry(QRect(130, 10, 62, 22));
        okButton = new QPushButton(dsc_ui);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(116, 40, 75, 23));

        retranslateUi(dsc_ui);

        QMetaObject::connectSlotsByName(dsc_ui);
    } // setupUi

    void retranslateUi(QWidget *dsc_ui)
    {
        dsc_ui->setWindowTitle(QCoreApplication::translate("dsc_ui", "Compress\303\243o de Escala Din\303\242mica", nullptr));
        label->setText(QCoreApplication::translate("dsc_ui", "c", nullptr));
        label_2->setText(QCoreApplication::translate("dsc_ui", "\316\263", nullptr));
        okButton->setText(QCoreApplication::translate("dsc_ui", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dsc_ui: public Ui_dsc_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSC_H
