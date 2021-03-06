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
    QWidget* corAtual;

private slots:
    // Arquivo
    void abrir();
    void salvar();
    void sair();
    // Opera??es
    void converteParaCinza();
    void dividirRGB();
    void inverteCinza();
    void inverteColorido();
    void equalizarHistograma();
    void addSaltPepper();
    void media3x3();
    void mediana3x3();
    void binariza();
    void laplaciano();
    void sobel();
    void drc();
    void limiariza();
    // Ajuda
    void janelaSobre();
    // Outros
    void copiaParaEsquerda();
    void converterRGB_HSL();
    void atualizarPos(int x, int y);
};
