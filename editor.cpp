#include "editor.h"
#include "sobre.h"
#include "divideRGB.h"
#include "conv_hsl.h"
#include "histoEq.h"
#include "SobelWindow.h"
#include "ui_limiariza.h"
#include <random>
#include <algorithm>
#include <functional>
#include <QFileDialog>
#include <cmath>

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
    connect(ui.actionSobel, &QAction::triggered, this, &editor::sobel);
    connect(ui.actionDRC, &QAction::triggered, this, &editor::drc);
    connect(ui.actionLiminha, &QAction::triggered, this, &editor::limiariza);
}

// Arquivo
void editor::abrir() {
    QString arquivoEscolhido = QFileDialog::getOpenFileName(
        this, tr("Abrir imagem"), "", tr("Bitmap (*bmp);;Todos os arquivos (*)")
    );

    if (arquivoEscolhido.isEmpty()) return;

    img.load(arquivoEscolhido);

    // Algumas imagens escala de cinza não são interpretadas como tais pelo Qt.
    // Isto é corrigido aqui.
    if (img.allGray() && img.format() != QImage::Format_Grayscale8)
        img = img.convertToFormat(QImage::Format_Grayscale8);

    // Redimensionando o QLabel para que ele exiba toda a imagem
    ui.label_img1->setFixedSize(img.width(), img.height());
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
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::convolucao(float *matriz, int mWidth, int mHeight) {
    imgB = img.copy();

    const int imgWidth = img.width(), imgHeight = img.height(),
        mCentroJ = mWidth >> 1, mCentroI = mHeight >> 1;
    int offsetJ = 0, offsetI = 0, limJ = 0, limI = 0, accCor; // (áté accCor) atribui 0 só pra não dar erro de "memória não incilizada"
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
            bitsB[i] = accCor;
        }
    }
}

// Versão overloaded de convolucao() para quando os valores precisam de algum tratamento,
// representado aqui pelo parâmetro f. Ex.: no filtro Laplaciano f(x) = |x| / 8.
void editor::convolucao(float* matriz, int mWidth, int mHeight, std::function<void(int*)> f) {
    imgB = img.copy();

    const int imgWidth = img.width(), imgHeight = img.height(),
        mCentroJ = mWidth >> 1, mCentroI = mHeight >> 1;
    int offsetJ = 0, offsetI = 0, limJ = 0, limI = 0, accCor; // (áté accCor) atribui 0 só pra não dar erro de "memória não incilizada"
    uchar* bitsB = nullptr, * bits = nullptr;

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
            f(&accCor);
            bitsB[i] = accCor;
        }
    }
}

void editor::convolucao(float* matriz, int mWidth, int mHeight, int *out) {
    const int imgWidth = img.width(), imgHeight = img.height(),
        mCentroJ = mWidth >> 1, mCentroI = mHeight >> 1;
    int offsetJ = 0, offsetI = 0, limJ = 0, limI = 0, accCor; // (áté accCor) atribui 0 só pra não dar erro de "memória não incilizada"
    uchar* bits = nullptr;

    for (int j = mCentroJ; j < imgHeight - mCentroJ; j++) { // p/ cada linha da imagem
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
            out[(imgWidth * j) + i] = accCor;
        }
    }
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

/*void print_matriz(int x, int y, int* m) {
    QDebug deb = qDebug();
    int i, j;
    for (j = 0; j < y; j++) {
        for (i = 0; i < x; i++) {
            deb.space() << m[(x * j) + i];
        }
        deb.nospace() << "\n";
    }
}*/

void editor::laplaciano4x4() {
    float laplaciano[] = { 0, -1, 0, -1, 4, -1, 0, -1, 0};
    convolucao(laplaciano, 3, 3, [](int *v) { *v = std::abs( * v) / 8; });
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::sobel() {
    int w = img.width(), h = img.height();
    // Não há vazamento de memória.
    // dx, dy e mag são excluídos pelo destrutor de SobelWindow.
    int* dx = new int[w * h], *dy = new int[w * h], *mag = new int[w * h], i, j, max = -256, min = 256;
    float sobel_x[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1}, sobel_y[] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
    convolucao(sobel_x, 3, 3, dx);
    convolucao(sobel_y, 3, 3, dy);
    // Calculando a magnitude e extraindo o máximo e o mínimo
    for (i = 1; i < w - 1; i++) {
        for (j = 1; j < h - 1; j++) {
            mag[(w * j) + i] = (int)std::sqrt((dx[(w * j) + i] * dx[(w * j) + i]) + (dy[(w * j) + i] * dy[(w * j) + i]));
            if (mag[(w * j) + i] > max)
                max = mag[(w * j) + i];
            if (mag[(w * j) + i] < min)
                min = mag[(w * j) + i];
        }
    }

    // Normalizando e montando imagem
    imgB = img.copy();
    uchar* bits = nullptr;
    for (j = 1; j < h - 1; j++) {
        bits = imgB.scanLine(j);
        for (i = 1; i < w - 1; i++)
            bits[i] = ((mag[(w * j) + i] - min) / (float)(max - min)) * 255;
    }

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));

    SobelWindow* sw = new SobelWindow(this, imgB, mag, dx, dy);
    sw->show();
}

void editor::drc() {
    float c = 1.0f, gamma = 1.4f;

    imgB = img.copy();
    uchar* bits = nullptr;
    for (int j = 0; j < img.height(); j++) {
        bits = imgB.scanLine(j);
        for (int i = 0; i < img.width(); i++)
            bits[i] = std::min(std::max(0, (int)(c * std::pow(bits[i], gamma))), 255);
    }

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::limiariza() {
    QDialog* dialog = new QDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose, true);
    Ui::ui_lim uid;
    uid.setupUi(dialog);
    connect(uid.okButton, &QPushButton::clicked, this, [=](void) {
        imgB = img.copy();
        int limiar = uid.spinBox->value();
        uchar* bits = nullptr;
        for (int j = 0; j < img.height(); j++) {
            bits = imgB.scanLine(j);
            for (int i = 0; i < img.width(); i++)
                if (bits[i] < limiar) bits[i] = 0;
        }
        ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
    });
    dialog->show();
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