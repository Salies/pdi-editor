#include "editor.h"
#include "sobre.h"
#include "divideRGB.h"
#include "conv_hsl.h"
#include "histoEq.h"
#include <random>
#include <algorithm>
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
    connect(ui.actionAddSaltPepper, &QAction::triggered, this, &editor::addSaltPepper);
    connect(ui.actionMedia3x3, &QAction::triggered, this, &editor::media3x3);
    connect(ui.actionMediana3x3, &QAction::triggered, this, &editor::mediana3x3);
    connect(ui.actionBinariza, &QAction::triggered, this, &editor::binariza);
    connect(ui.actionLaplaciano4x4, &QAction::triggered, this, &editor::laplaciano4x4);
}

// Arquivo
void editor::abrir() {
    QString arquivoEscolhido = QFileDialog::getOpenFileName(
        this, tr("Abrir imagem"), "", tr("Bitmap (*bmp);;Todos os arquivos (*)")
    );
    img.load(arquivoEscolhido);

    // Algumas imagens escala de cinza não são interpretadas como tais pelo Qt.
    // Isto é corrigido aqui.
    if (img.allGray() && img.format() != QImage::Format_Grayscale8)
        img = img.convertToFormat(QImage::Format_Grayscale8);

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

// Nesta função: por que castar para QRgb? Pois a ordem de RGB
// muda de acordo com a ordem de bytes da máquina. Logo, é melhor
// deixar o Qt responsável por determiná-la. Isso (casting) não é
// necessário nas funções p/ imagens em escala de cinza, visto que
// guardam apenas uma cor por byte, ou seja, independem de ordem
// (o vetor é sempre a imagem linearizada).
void editor::converteParaCinza() {
    if (img.isGrayscale()) return;

    imgB = img.copy();
    uchar cinza;
    QRgb* data;
    for (int j = 0; j < img.height(); j++) {
        data = (QRgb*)(imgB.scanLine(j));
        for (int i = 0; i < img.width(); i++) {
            cinza = (qRed(data[i]) + qGreen(data[i]) + qBlue(data[i])) / 3;
            data[i] = qRgb(cinza, cinza, cinza);
        }
    }

    imgB = imgB.convertToFormat(QImage::Format_Grayscale8);

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::inverteCinza() {
    if (!img.isGrayscale()) return;

    imgB = img.copy();
    uchar* bits = nullptr;

    for (int j = 0; j < img.height(); j++) {
        bits = imgB.scanLine(j);
        for (int i = 0; i < img.width(); i++)
            bits[i] = 255 - bits[i];
    }

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::inverteColorido() {
    if (img.isGrayscale()) return;

    imgB = img.copy();
    QRgb* data;
    for (int j = 0; j < img.height(); j++) {
        data = (QRgb*)(imgB.scanLine(j));
        for (int i = 0; i < img.width(); i++)
            data[i] = qRgb(255 - qRed(data[i]), 255 - qGreen(data[i]), 255 - qBlue(data[i]));
    }

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::dividirRGB() {
    divideRGB* d = new divideRGB(img);
    d->show();
}

void editor::equalizarHistograma() {
    if (!img.isGrayscale()) return;

    histoEq* eq = new histoEq(img, &imgB, ui.label_img2);
    eq->show();
}

void editor::addSaltPepper() {
    if (!img.isGrayscale()) return;

    imgB = img.copy();
    int size = img.width() * img.height();
    int cores[2] = { 0, 255 };
    uchar* bits = imgB.scanLine(0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, size - 1);
    std::uniform_int_distribution<> distCor(0, 1);

    for (int i = 0; i < size / 10; i++)
        bits[dist(gen)] = cores[distCor(gen)];

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::media3x3() {
    float cte = 1.0f / 9.0f;
    float media[] = { cte, cte, cte, cte, cte, cte, cte, cte, cte };
    convolucao(media, 3, 3);
}

void editor::convolucao(float *matriz, int mWidth, int mHeight, int div) {
    imgB = img.copy();

    const int imgWidth = img.width(), imgHeight = img.height(),
        mCentroJ = mWidth >> 1, mCentroI = mHeight >> 1;
    int offsetJ = 0, offsetI = 0, limJ = 0, limI = 0, accCor = 0; // (áté accCor) atribui 0 só pra não dar erro de "memória não incilizada"
    uchar* bitsB = nullptr, *bits = nullptr;

    for (int j = mCentroJ; j < imgHeight - mCentroJ; j++) { // p/ cada linha da imagem
        bitsB = imgB.scanLine(j);
        for (int i = mCentroI; i < imgWidth - mCentroI; i++) { // p/ cada coluna da imagem
            accCor = 0;
            for (int mj = 0; mj < mHeight; mj++) { // p/ cada linha da matriz de convolução
                // a matriz de covolução será "espelhada"
                offsetJ = mHeight - mj - 1;
                limJ = j + mCentroI - offsetJ;
                bits = img.scanLine(limJ);
                for (int mi = 0; mi < mWidth; mi++) { // p/ cada cluna da matriz de convolução
                    offsetI = mWidth - mi - 1;
                    limI = i + mCentroJ - offsetI;
                    if (limJ >= 0 && limJ < imgHeight && limI >= 0 && limI < imgWidth) {
                        accCor += bits[limI] * matriz[(mWidth * offsetJ) + offsetI];
                    }
                }
            }
            bitsB[i] = accCor / div;
        }
    }

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::mediana(int mWidth, int mHeight) {
    const int imgWidth = img.width(), imgHeight = img.height(),
        mCentroJ = mWidth >> 1, mCentroI = mHeight >> 1, mCentro = (mWidth * mHeight) >> 1;
    int offsetJ = 0, offsetI = 0, limJ = 0, limI = 0;
    int pos; // posição atual do vetor mediana
    imgB = img.copy();
    uchar* bits = nullptr, *bitsB = nullptr;
    std::vector<uchar> mdn(mWidth * mHeight);

    for (int j = mCentroJ; j < imgHeight - mCentroJ; j++) { // p/ cada linha da imagem
        bitsB = imgB.scanLine(j);
        for (int i = mCentroI; i < imgWidth - mCentroI; i++) { // p/ cada coluna da imagem
            pos = 0;
            for (int mj = 0; mj < mHeight; mj++) { // p/ cada linha da matriz de convolução
                // a matriz de covolução será "espelhada"
                offsetJ = mHeight - mj - 1;
                limJ = j + mCentroI - offsetJ;
                bits = img.scanLine(limJ);
                for (int mi = 0; mi < mWidth; mi++) { // p/ cada cluna da matriz de convolução
                    offsetI = mWidth - mi - 1;
                    limI = i + mCentroJ - offsetI;
                    if (limJ >= 0 && limJ < imgHeight && limI >= 0 && limI < imgWidth) {
                        mdn[pos] = bits[limI];
                        pos++;
                    }
                }
            }
            std::sort(mdn.begin(), mdn.end());
            bitsB[i] = mdn[mCentro];
        }
    }

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::mediana3x3() {
    mediana(3, 3);
}

void editor::binariza() {
    imgB = img.copy();

    uchar* bits = nullptr;
    for (int j = 0; j < img.height(); j++) {
        bits = imgB.scanLine(j);
        for (int i = 0; i < img.width(); i++) {
            if (bits[i] < 128) {
                bits[i] = 0;
                continue;
            }
            bits[i] = 255;
        }
    }

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::laplaciano4x4() {
    float laplaciano[] = { 0, -1, 0, -1, 4, -1, 0, -1, 0};
    convolucao(laplaciano, 3, 3, 8);
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

    // Como o acesso aqui é pontual, acessamos pelo método pixelColor(),
    // ineficiente em manipulações de muitos pixels (como as implementadas aqui).
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
// modalidade não precisa, já tem no designer