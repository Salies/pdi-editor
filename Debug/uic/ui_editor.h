/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "mainlabel.h"

QT_BEGIN_NAMESPACE

class Ui_editorClass
{
public:
    QAction *action_Abrir;
    QAction *action_paraCinza;
    QAction *actionGuia_b_sico;
    QAction *actionSobre;
    QAction *actionDividir_RGB;
    QAction *actionInverte_cinza;
    QAction *actionInverte_colorida;
    QAction *actionSalvar;
    QAction *actionConverter_RGB_HSL;
    QAction *actionSair;
    QAction *actionEqualizarHistograma;
    QAction *actionAddSaltPepper;
    QAction *actionMedia3x3;
    QAction *actionMediana3x3;
    QAction *actionBinariza;
    QAction *actionLaplaciano4x4;
    QAction *actionSobel;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scroll_img1;
    MainLabel *label_img1;
    QPushButton *pushButton;
    QScrollArea *scroll_img2;
    QLabel *label_img2;
    QMenuBar *menuBar;
    QMenu *menu_Arquivo;
    QMenu *menu_Operacoes;
    QMenu *menuAjuda;
    QMenu *menuOutros;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *editorClass)
    {
        if (editorClass->objectName().isEmpty())
            editorClass->setObjectName(QString::fromUtf8("editorClass"));
        editorClass->resize(1196, 594);
        action_Abrir = new QAction(editorClass);
        action_Abrir->setObjectName(QString::fromUtf8("action_Abrir"));
        action_paraCinza = new QAction(editorClass);
        action_paraCinza->setObjectName(QString::fromUtf8("action_paraCinza"));
        actionGuia_b_sico = new QAction(editorClass);
        actionGuia_b_sico->setObjectName(QString::fromUtf8("actionGuia_b_sico"));
        actionSobre = new QAction(editorClass);
        actionSobre->setObjectName(QString::fromUtf8("actionSobre"));
        actionDividir_RGB = new QAction(editorClass);
        actionDividir_RGB->setObjectName(QString::fromUtf8("actionDividir_RGB"));
        actionInverte_cinza = new QAction(editorClass);
        actionInverte_cinza->setObjectName(QString::fromUtf8("actionInverte_cinza"));
        actionInverte_colorida = new QAction(editorClass);
        actionInverte_colorida->setObjectName(QString::fromUtf8("actionInverte_colorida"));
        actionSalvar = new QAction(editorClass);
        actionSalvar->setObjectName(QString::fromUtf8("actionSalvar"));
        actionConverter_RGB_HSL = new QAction(editorClass);
        actionConverter_RGB_HSL->setObjectName(QString::fromUtf8("actionConverter_RGB_HSL"));
        actionSair = new QAction(editorClass);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionEqualizarHistograma = new QAction(editorClass);
        actionEqualizarHistograma->setObjectName(QString::fromUtf8("actionEqualizarHistograma"));
        actionAddSaltPepper = new QAction(editorClass);
        actionAddSaltPepper->setObjectName(QString::fromUtf8("actionAddSaltPepper"));
        actionMedia3x3 = new QAction(editorClass);
        actionMedia3x3->setObjectName(QString::fromUtf8("actionMedia3x3"));
        actionMediana3x3 = new QAction(editorClass);
        actionMediana3x3->setObjectName(QString::fromUtf8("actionMediana3x3"));
        actionBinariza = new QAction(editorClass);
        actionBinariza->setObjectName(QString::fromUtf8("actionBinariza"));
        actionLaplaciano4x4 = new QAction(editorClass);
        actionLaplaciano4x4->setObjectName(QString::fromUtf8("actionLaplaciano4x4"));
        actionSobel = new QAction(editorClass);
        actionSobel->setObjectName(QString::fromUtf8("actionSobel"));
        centralWidget = new QWidget(editorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scroll_img1 = new QScrollArea(centralWidget);
        scroll_img1->setObjectName(QString::fromUtf8("scroll_img1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scroll_img1->sizePolicy().hasHeightForWidth());
        scroll_img1->setSizePolicy(sizePolicy);
        scroll_img1->setMinimumSize(QSize(514, 514));
        scroll_img1->setWidgetResizable(true);
        label_img1 = new MainLabel();
        label_img1->setObjectName(QString::fromUtf8("label_img1"));
        label_img1->setGeometry(QRect(0, 0, 512, 512));
        label_img1->setMinimumSize(QSize(0, 0));
        scroll_img1->setWidget(label_img1);

        horizontalLayout->addWidget(scroll_img1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(90, 60));
        QFont font;
        font.setPointSize(24);
        font.setKerning(true);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        scroll_img2 = new QScrollArea(centralWidget);
        scroll_img2->setObjectName(QString::fromUtf8("scroll_img2"));
        sizePolicy.setHeightForWidth(scroll_img2->sizePolicy().hasHeightForWidth());
        scroll_img2->setSizePolicy(sizePolicy);
        scroll_img2->setMinimumSize(QSize(514, 514));
        scroll_img2->setWidgetResizable(true);
        label_img2 = new QLabel();
        label_img2->setObjectName(QString::fromUtf8("label_img2"));
        label_img2->setGeometry(QRect(0, 0, 512, 512));
        label_img2->setScaledContents(false);
        scroll_img2->setWidget(label_img2);

        horizontalLayout->addWidget(scroll_img2);

        editorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(editorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1196, 21));
        menu_Arquivo = new QMenu(menuBar);
        menu_Arquivo->setObjectName(QString::fromUtf8("menu_Arquivo"));
        menu_Operacoes = new QMenu(menuBar);
        menu_Operacoes->setObjectName(QString::fromUtf8("menu_Operacoes"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QString::fromUtf8("menuAjuda"));
        menuOutros = new QMenu(menuBar);
        menuOutros->setObjectName(QString::fromUtf8("menuOutros"));
        editorClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(editorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        editorClass->setStatusBar(statusBar);

        menuBar->addAction(menu_Arquivo->menuAction());
        menuBar->addAction(menu_Operacoes->menuAction());
        menuBar->addAction(menuOutros->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menu_Arquivo->addAction(action_Abrir);
        menu_Arquivo->addAction(actionSalvar);
        menu_Arquivo->addSeparator();
        menu_Arquivo->addAction(actionSair);
        menu_Operacoes->addAction(actionInverte_cinza);
        menu_Operacoes->addAction(actionEqualizarHistograma);
        menu_Operacoes->addAction(actionAddSaltPepper);
        menu_Operacoes->addAction(actionMedia3x3);
        menu_Operacoes->addAction(actionMediana3x3);
        menu_Operacoes->addAction(actionBinariza);
        menu_Operacoes->addAction(actionLaplaciano4x4);
        menu_Operacoes->addAction(actionSobel);
        menu_Operacoes->addSeparator();
        menu_Operacoes->addAction(action_paraCinza);
        menu_Operacoes->addAction(actionInverte_colorida);
        menu_Operacoes->addSeparator();
        menu_Operacoes->addAction(actionDividir_RGB);
        menuAjuda->addAction(actionGuia_b_sico);
        menuAjuda->addSeparator();
        menuAjuda->addAction(actionSobre);
        menuOutros->addAction(actionConverter_RGB_HSL);

        retranslateUi(editorClass);

        QMetaObject::connectSlotsByName(editorClass);
    } // setupUi

    void retranslateUi(QMainWindow *editorClass)
    {
        editorClass->setWindowTitle(QCoreApplication::translate("editorClass", "PDI ~ Editor de imagens", nullptr));
        action_Abrir->setText(QCoreApplication::translate("editorClass", "&Abrir", nullptr));
        action_paraCinza->setText(QCoreApplication::translate("editorClass", "&Converter para cinza", nullptr));
        actionGuia_b_sico->setText(QCoreApplication::translate("editorClass", "Guia b\303\241sico", nullptr));
        actionSobre->setText(QCoreApplication::translate("editorClass", "Sobre", nullptr));
        actionDividir_RGB->setText(QCoreApplication::translate("editorClass", "Separar os canais da imagem (RGB)", nullptr));
        actionInverte_cinza->setText(QCoreApplication::translate("editorClass", "Inverter imagem cinza", nullptr));
        actionInverte_colorida->setText(QCoreApplication::translate("editorClass", "Inverter imagem colorida", nullptr));
        actionSalvar->setText(QCoreApplication::translate("editorClass", "Salvar", nullptr));
        actionConverter_RGB_HSL->setText(QCoreApplication::translate("editorClass", "Converter RGB/HSL", nullptr));
        actionSair->setText(QCoreApplication::translate("editorClass", "Sair", nullptr));
        actionEqualizarHistograma->setText(QCoreApplication::translate("editorClass", "Equalizar histograma", nullptr));
        actionAddSaltPepper->setText(QCoreApplication::translate("editorClass", "Adicionar ru\303\255do sal e pimenta (10%)", nullptr));
        actionMedia3x3->setText(QCoreApplication::translate("editorClass", "M\303\251dia 3x3", nullptr));
        actionMediana3x3->setText(QCoreApplication::translate("editorClass", "Mediana 3x3", nullptr));
        actionBinariza->setText(QCoreApplication::translate("editorClass", "Binariza\303\247\303\243o", nullptr));
        actionLaplaciano4x4->setText(QCoreApplication::translate("editorClass", "Laplaciano (3x3)", nullptr));
        actionSobel->setText(QCoreApplication::translate("editorClass", "Sobel", nullptr));
        label_img1->setProperty("text", QVariant(QString()));
        pushButton->setText(QCoreApplication::translate("editorClass", "\360\237\241\204", nullptr));
        label_img2->setText(QString());
        menu_Arquivo->setTitle(QCoreApplication::translate("editorClass", "&Arquivo", nullptr));
        menu_Operacoes->setTitle(QCoreApplication::translate("editorClass", "&Opera\303\247\303\265es", nullptr));
        menuAjuda->setTitle(QCoreApplication::translate("editorClass", "Ajuda", nullptr));
        menuOutros->setTitle(QCoreApplication::translate("editorClass", "Utilit\303\241rios", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editorClass: public Ui_editorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
