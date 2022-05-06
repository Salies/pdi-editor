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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editorClass
{
public:
    QAction *action_Abrir;
    QAction *action_paraCinza;
    QAction *actionGuia_b_sico;
    QAction *actionSobre;
    QWidget *centralWidget;
    QScrollArea *scroll_img1;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_img1;
    QScrollArea *scroll_img2;
    QWidget *scrollAreaWidgetContents_4;
    QLabel *label_img2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menu_Arquivo;
    QMenu *menu_Operacoes;
    QMenu *menuAjuda;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *editorClass)
    {
        if (editorClass->objectName().isEmpty())
            editorClass->setObjectName(QString::fromUtf8("editorClass"));
        editorClass->resize(1271, 631);
        action_Abrir = new QAction(editorClass);
        action_Abrir->setObjectName(QString::fromUtf8("action_Abrir"));
        action_paraCinza = new QAction(editorClass);
        action_paraCinza->setObjectName(QString::fromUtf8("action_paraCinza"));
        actionGuia_b_sico = new QAction(editorClass);
        actionGuia_b_sico->setObjectName(QString::fromUtf8("actionGuia_b_sico"));
        actionSobre = new QAction(editorClass);
        actionSobre->setObjectName(QString::fromUtf8("actionSobre"));
        centralWidget = new QWidget(editorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        scroll_img1 = new QScrollArea(centralWidget);
        scroll_img1->setObjectName(QString::fromUtf8("scroll_img1"));
        scroll_img1->setGeometry(QRect(20, 20, 512, 512));
        scroll_img1->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 510, 510));
        label_img1 = new QLabel(scrollAreaWidgetContents);
        label_img1->setObjectName(QString::fromUtf8("label_img1"));
        label_img1->setGeometry(QRect(0, 0, 512, 512));
        scroll_img1->setWidget(scrollAreaWidgetContents);
        scroll_img2 = new QScrollArea(centralWidget);
        scroll_img2->setObjectName(QString::fromUtf8("scroll_img2"));
        scroll_img2->setGeometry(QRect(730, 20, 512, 512));
        scroll_img2->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 510, 510));
        label_img2 = new QLabel(scrollAreaWidgetContents_4);
        label_img2->setObjectName(QString::fromUtf8("label_img2"));
        label_img2->setGeometry(QRect(0, 0, 512, 512));
        label_img2->setScaledContents(true);
        scroll_img2->setWidget(scrollAreaWidgetContents_4);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(590, 230, 91, 61));
        QFont font;
        font.setPointSize(24);
        pushButton->setFont(font);
        editorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(editorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1271, 22));
        menu_Arquivo = new QMenu(menuBar);
        menu_Arquivo->setObjectName(QString::fromUtf8("menu_Arquivo"));
        menu_Operacoes = new QMenu(menuBar);
        menu_Operacoes->setObjectName(QString::fromUtf8("menu_Operacoes"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QString::fromUtf8("menuAjuda"));
        editorClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(editorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        editorClass->setStatusBar(statusBar);

        menuBar->addAction(menu_Arquivo->menuAction());
        menuBar->addAction(menu_Operacoes->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menu_Arquivo->addAction(action_Abrir);
        menu_Operacoes->addAction(action_paraCinza);
        menuAjuda->addAction(actionGuia_b_sico);
        menuAjuda->addSeparator();
        menuAjuda->addAction(actionSobre);

        retranslateUi(editorClass);

        QMetaObject::connectSlotsByName(editorClass);
    } // setupUi

    void retranslateUi(QMainWindow *editorClass)
    {
        editorClass->setWindowTitle(QCoreApplication::translate("editorClass", "editor", nullptr));
        action_Abrir->setText(QCoreApplication::translate("editorClass", "&Abrir", nullptr));
        action_paraCinza->setText(QCoreApplication::translate("editorClass", "&Converter para cinza", nullptr));
        actionGuia_b_sico->setText(QCoreApplication::translate("editorClass", "Guia b\303\241sico", nullptr));
        actionSobre->setText(QCoreApplication::translate("editorClass", "Sobre", nullptr));
        label_img1->setText(QString());
        label_img2->setText(QString());
        pushButton->setText(QCoreApplication::translate("editorClass", "\360\237\241\204", nullptr));
        menu_Arquivo->setTitle(QCoreApplication::translate("editorClass", "&Arquivo", nullptr));
        menu_Operacoes->setTitle(QCoreApplication::translate("editorClass", "&Opera\303\247\303\265es", nullptr));
        menuAjuda->setTitle(QCoreApplication::translate("editorClass", "Ajuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editorClass: public Ui_editorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
