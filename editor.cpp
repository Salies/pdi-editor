#include "editor.h"
#include "sobre.h"
#include "divideRGB.h"
#include "conv_hsl.h"
#include "histoEq.h"
#include <QFileDialog>

#include <qwt_plot.h>
#include <qwt_plot_barchart.h>
#include <qwt_plot_curve.h>

#include <QDebug>

editor::editor(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


    // Define mensagem padrão da statusBar (onde são mostrados os pixels)
    sbMsg = new QLabel("<b>x:</b> 0, <b>y:</b> 0, <b>cor:</b> RGB(0, 0, 0)");
    corAtual = new QWidget();
    corAtual->setFixedSize(32, 16);
    corAtual->setAutoFillBackground(true);

    ui.statusBar->addWidget(sbMsg);
    ui.statusBar->addWidget(corAtual);

    // Conexões (coneta a ação do menu/botões a uma função)
    connect(ui.actionSair, &QAction::triggered, this, &editor::sair);
    connect(ui.pushButton, &QPushButton::clicked, this, &editor::copiaParaEsquerda);
    connect(ui.action_Abrir, &QAction::triggered, this, &editor::abrir);
    connect(ui.action_paraCinza, &QAction::triggered, this, &editor::converteParaCinza);
    connect(ui.actionDividir_RGB, &QAction::triggered, this, &editor::dividirRGB);
    connect(ui.actionSobre, &QAction::triggered, this, &editor::janelaSobre);
    connect(ui.actionInverte_cinza, &QAction::triggered, this, &editor::inverteCinza);
    connect(ui.actionInverte_colorida, &QAction::triggered, this, &editor::inverteColorido);
    connect(ui.actionSalvar, &QAction::triggered, this, &editor::salvar);
    connect(ui.label_img1, &MainLabel::novaPos, this, &editor::atualizarPos);
    connect(ui.actionConverter_RGB_HSL, &QAction::triggered, this, &editor::converterRGB_HSL);
    connect(ui.actionEqualizarHistograma, &QAction::triggered, this, &editor::equalizarHistograma);
}

// Arquivo
void editor::abrir() {
    QString arquivoEscolhido = QFileDialog::getOpenFileName(
        this, tr("Abrir imagem"), "", tr("Bitmap (*bmp);;Todos os arquivos (*)")
    );
    img.load(arquivoEscolhido);
    // Redimensionando o QLabel para que ele exiba toda a imagem
    ui.label_img1->resize(img.width(), img.height());
    ui.label_img1->setPixmap(QPixmap::fromImage(img));
}

void editor::salvar() {
    QString arquivoSalvar = QFileDialog::getSaveFileName(this, tr("Salvar imagem"), "imagem.bmp", tr("Bitmap (*bmp);"));
    img.save(arquivoSalvar);
}

void editor::sair() {
    close(); 
    // O QApplication é automaticamente terminado quando sua última janela (no caso a principal) é fechada
    // setQuitOnLastWindowClosed é true por padrão
}

// Operações
void editor::converteParaCinza() {
    if (img.isGrayscale()) return;

    imgB = img.copy();
    uchar* bits = imgB.bits();
    int cinza;
    for (int i = 0; i < (imgB.width() * imgB.height() * 4); i+=4)
    {
        cinza = (bits[i] + bits[i + 1] + bits[i + 2]) / 3;
        bits[i] = cinza;
        bits[i + 1] = cinza;
        bits[i + 2] = cinza;
    }

    imgB = imgB.convertToFormat(QImage::Format_Grayscale8);

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::inverteCinza() {
    if (!img.isGrayscale()) return;

    imgB = img.copy();
    uchar* bits = imgB.bits();
    for (int i = 0; i < (imgB.width() * imgB.height()); i ++)
        bits[i] = 255 - bits[i];
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::inverteColorido() {
    if (img.isGrayscale()) return;

    imgB = img.copy();
    uchar* bits = imgB.bits();
    for (int i = 0; i < (imgB.width() * imgB.height() * 4); i += 4)
    {
        bits[i] = 255 - bits[i];
        bits[i + 1] = 255 - bits[i + 1];
        bits[i + 2] = 255 - bits[i + 2];
    }

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::dividirRGB() {
    divideRGB* d = new divideRGB(img);
    d->show();
}

void editor::equalizarHistograma() {
    if (!img.isGrayscale()) return;

    histoEq* eq = new histoEq(&img);
    eq->show();
}

// Ajuda
void editor::janelaSobre() {
    sobre *s = new sobre();
    s->exec();
}

// Outros
void editor::copiaParaEsquerda() {
    if (imgB.isNull()) return;
    img = imgB.copy();
    ui.label_img1->setPixmap(*ui.label_img2->pixmap());
}

void editor::atualizarPos(int x, int y) {
    if (!img.valid(x, y)) return;

    QColor cor = img.pixelColor(x, y);
    corAtual->setPalette(cor);
    sbMsg->setText("<b>x:</b> " + QString::number(x) + ", <b>y:</b> " + QString::number(y) +
    ", <b>cor:</b> RGB(" + QString::number(cor.red()) + ", " + QString::number(cor.green()) + ", " + QString::number(cor.blue()) + ")");
}

void editor::converterRGB_HSL() {
    conv_hsl* conv = new conv_hsl();
    conv->show();
}

// TODO DESATIVAR OPÇÕES CINZA SE A IMAGEM FOR CINZA, E VICE VERSA
// ^^^ AGRUPAR, FICA MAIS FÁCIL DE DESATIVAR

// TODO FAZER BASE DE JANELA COM MODALIDADE E LIMPEZA DE MEMÓRIA
// ^^ HERANÇA MÚLTIPLA (PRA NÃO ZOAR O DESIGNER)?