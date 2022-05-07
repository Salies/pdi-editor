/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
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
        label_img2->setScaledContents(true);
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
        menu_Operacoes->addAction(actionInverte_cinza);
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
