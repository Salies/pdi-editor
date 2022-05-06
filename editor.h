#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_editor.h"
     
class editor : public QMainWindow
{
    Q_OBJECT

public:
    editor(QWidget *parent = Q_NULLPTR);

private:
    Ui::editorClass ui;
    QImage img, imgB; // imagem a ser manipulada
    QLabel *sbMsg;
    void atualizarPos(int x, int y);

private slots:
    // Arquivo
    void abrir();
    void salvar();
    // Opera��es
    void converteParaCinza();
    void dividirRGB();
    void inverteCinza();
    void inverteColorido();
    // Ajuda
    void janelaSobre();
    // Outros
    void copiaParaEsquerda();
};
