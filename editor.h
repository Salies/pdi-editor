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
    // Operações
    void converteParaCinza();
    void dividirRGB();
    void inverteCinza();
    void inverteColorido();
    void equalizarHistograma();
    void addSaltPepper();
    void media3x3();
    void mediana3x3();
    void mediana(int mWidth, int mHeight);
    void convolucao(float* matriz, int mWidth, int mHeight);
    void convolucao(float* matriz, int mWidth, int mHeight, std::function<void(int*)> f);
    void convolucao(float* matriz, int mWidth, int mHeight, int *out);
    void binariza();
    void laplaciano4x4();
    void sobel();
    // Ajuda
    void janelaSobre();
    // Outros
    void copiaParaEsquerda();
    void converterRGB_HSL();
    void atualizarPos(int x, int y);
};
