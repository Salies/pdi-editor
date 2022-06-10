/********************************************************************************
** Form generated from reading UI file 'sobre.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOBRE_H
#define UI_SOBRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Sobre
{
public:
    QLabel *label;

    void setupUi(QDialog *Sobre)
    {
        if (Sobre->objectName().isEmpty())
            Sobre->setObjectName(QString::fromUtf8("Sobre"));
        Sobre->resize(412, 103);
        Sobre->setModal(true);
        label = new QLabel(Sobre);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 361, 81));
        label->setTextFormat(Qt::PlainText);
        label->setWordWrap(true);

        retranslateUi(Sobre);

        QMetaObject::connectSlotsByName(Sobre);
    } // setupUi

    void retranslateUi(QDialog *Sobre)
    {
        Sobre->setWindowTitle(QCoreApplication::translate("Sobre", "Sobre", nullptr));
        label->setText(QCoreApplication::translate("Sobre", "2022 - Daniel Serezane.\n"
"Editor b\303\241sico de imagens. Constru\303\255do durante a disciplina de Processamento Digital de Imagens, ministrada na FCT-UNESP.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sobre: public Ui_Sobre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOBRE_H
