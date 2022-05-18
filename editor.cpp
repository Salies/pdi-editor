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


    // Define mensagem padr�o da statusBar (onde s�o mostrados os pixels)
    sbMsg = new QLabel("<b>x:</b> 0, <b>y:</b> 0, <b>cor:</b> RGB(0, 0, 0)");
    corAtual = new QWidget();
    corAtual->setFixedSize(32, 16);
    corAtual->setAutoFillBackground(true);

    ui.statusBar->addWidget(sbMsg);
    ui.statusBar->addWidget(corAtual);

    // Conex�es (coneta a a��o do menu/bot�es a uma fun��o)
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
}

// Arquivo
void editor::abrir() {
    QString arquivoEscolhido = QFileDialog::getOpenFileName(
        this, tr("Abrir imagem"), "", tr("Bitmap (*bmp);;Todos os arquivos (*)")
    );
    img.load(arquivoEscolhido);

    // Algumas imagens escala de cinza n�o s�o interpretadas como tais pelo Qt.
    // Isto � corrigido aqui.
    QImage::Format f = img.format();
    if (img.isGrayscale() && f != QImage::Format_Grayscale8 && f != QImage::Format_Indexed8) {
        qDebug() << "Formato atual:" << img.format();
        img = img.convertToFormat(QImage::Format_Grayscale8);
    }

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
    // O QApplication � automaticamente terminado quando sua �ltima janela (no caso a principal) � fechada
    // setQuitOnLastWindowClosed � true por padr�o
}

// Opera��es

// Nesta fun��o: por que castar para QRgb? Pois a ordem de RGB
// muda de acordo com a ordem de bytes da m�quina. Logo, � melhor
// deixar o Qt respons�vel por determin�-la. Isso (casting) n�o �
// necess�rio nas fun��es p/ imagens em escala de cinza, visto que
// guardam apenas uma cor por byte, ou seja, independem de ordem
// (o vetor � sempre a imagem linearizada).
void editor::converteParaCinza() {
    if (img.isGrayscale()) return;

    imgB = img.copy();
    uchar cinza;
    QRgb* data = (QRgb*)(imgB.bits());
    for (int i = 0; i < (imgB.width() * imgB.height()); i++) {
        cinza = (qRed(data[i]) + qGreen(data[i]) + qBlue(data[i])) / 3;
        data[i] = qRgb(cinza, cinza, cinza);
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
    QRgb* data = (QRgb*)(imgB.bits());
    for (int i = 0; i < (imgB.width() * imgB.height()); i ++)
        data[i] = qRgb(255 - qRed(data[i]), 255 - qGreen(data[i]), 255 - qBlue(data[i]));

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
    uchar* bits = imgB.bits();
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

void editor::convolucao(float *matriz, int mWidth, int mHeight) {
    const int imgWidth = img.width(), imgHeight = img.height(),
        mCentroJ = mWidth / 2, mCentroI = mHeight / 2;
    int offsetJ = 0, offsetI = 0, limJ = 0, limI = 0; // atribui 0 s� pra n�o dar erro de "mem�ria n�o incilizada"

    imgB = img.copy();
    uchar* bits = img.bits(), *bitsB = imgB.bits(), accCor;

    for (int j = 0; j < imgHeight; j++) { // p/ cada linha da imagem
        for (int i = 0; i < imgWidth; i++) { // p/ cada coluna da imagem
            accCor = 0;
            for (int mj = 0; mj < mHeight; mj++) { // p/ cada linha da matriz de convolu��o
                // a matriz de covolu��o ser� "espelhada"
                offsetJ = mHeight - mj - 1;
                for (int mi = 0; mi < mWidth; mi++) { // p/ cada cluna da matriz de convolu��o
                    offsetI = mWidth - mi - 1;
                    limJ = j + mCentroI - offsetJ;
                    limI = i + mCentroJ - offsetI;
                    if (limJ >= 0 && limJ < imgHeight && limI >= 0 && limI < imgWidth)
                        accCor += bits[(imgWidth * limJ) + limI] * matriz[(mWidth * offsetJ) + offsetI];
                }
            }
            bitsB[(imgWidth * j) + i] = accCor;
        }
    }

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

// TODO: CONSERTAR ACESSO ILEGAL A MEMORIA
void editor::mediana(int mWidth, int mHeight) {
    const int mCentroJ = mWidth / 2, mCentroI = mHeight / 2,
        imgWidth = img.width(), imgHeight = img.height();
    int pos; // posi��o atual do vetor mediana
    imgB = img.copy();
    const uchar* bits = img.bits();
    uchar *bitsB = imgB.bits();
    std::vector<uchar> mdn(mWidth * mHeight);

    // CONSERTAR FOR
    /*for (int j = 0; j < img.width() - mCentroJ; j++) {
        for (int i = 0; i < img.height() - mCentroI; i++) {
            pos = 0;
            for (int mj = 0; mj < mWidth; mj++) {
                for (int mi = 0; mi < mHeight; mi++) {
                    mdn[pos] = bits[(imgWidth * (j + mj - mCentroJ)) + i + mi - mCentroI]; // ESTOURANDO AQUI
                    pos++;
                }
            }
            std::sort(mdn.begin(), mdn.end());
            bitsB[(imgWidth * j) + i] = mdn[(int)std::round((mWidth * mHeight) / 2)];
        }
    }*/

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::mediana3x3() {
    mediana(3, 3);
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

    // Como o acesso aqui � pontual, acessamos pelo m�todo pixelColor(),
    // ineficiente em manipula��es de muitos pixels (como as implementadas aqui).
    QColor cor = img.pixelColor(x, y);
    corAtual->setPalette(cor);
    sbMsg->setText("<b>x:</b> " + QString::number(x) + ", <b>y:</b> " + QString::number(y) +
    ", <b>cor:</b> RGB(" + QString::number(cor.red()) + ", " + QString::number(cor.green()) + ", " + QString::number(cor.blue()) + ")");
}

void editor::converterRGB_HSL() {
    conv_hsl* conv = new conv_hsl();
    conv->show();
}

// TODO DESATIVAR OP��ES CINZA SE A IMAGEM FOR CINZA, E VICE VERSA
// ^^^ AGRUPAR, FICA MAIS F�CIL DE DESATIVAR

// TODO FAZER BASE DE JANELA COM MODALIDADE E LIMPEZA DE MEM�RIA
// ^^ HERAN�A M�LTIPLA (PRA N�O ZOAR O DESIGNER)?
// modalidade n�o precisa, j� tem no designer