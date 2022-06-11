#include "editor.h"
#include "sobre.h"
#include "divideRGB.h"
#include "conv_hsl.h"
#include "histoEq.h"
#include "SobelWindow.h"
#include "ui_limiariza.h"
#include "ui_dsc.h"
#include <QFileDialog>

#include "slithice/slithice.h"

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
    connect(ui.actionLaplaciano, &QAction::triggered, this, &editor::laplaciano);
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

    // Formatos podem ser "estranhos", converter para um seguro (RGB32).
    img = img.convertToFormat(QImage::Format_RGB32);
    ui.menuOperacoes_img_colorida->setEnabled(true);
    ui.menu_Operacoes->setEnabled(false);

    // Algumas imagens escala de cinza não são interpretadas como tais pelo Qt.
    // Isto é corrigido aqui.
    if (img.allGray() || img.isGrayscale()) {
        img = img.convertToFormat(QImage::Format_Grayscale8);
        ui.menuOperacoes_img_colorida->setEnabled(false);
        ui.menu_Operacoes->setEnabled(true);
    }

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
void editor::converteParaCinza() {
    if (img.isGrayscale()) return;

    imgB = QImage(img.width(), img.height(), QImage::Format_Grayscale8);
    slithice::to_grayscale(img, imgB);
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::inverteCinza() {
    if (!img.isGrayscale()) return;

    imgB = QImage(img.width(), img.height(), QImage::Format_Grayscale8);
    slithice::invert_gray(img, imgB);
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::inverteColorido() {
    if (img.isGrayscale()) return;

    imgB = QImage(img.width(), img.height(), QImage::Format_RGB32);
    slithice::invert(img, imgB);
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::dividirRGB() {
    divideRGB* d = new divideRGB(img);
    d->show();
    delete d;
}

void editor::equalizarHistograma() {
    if (!img.isGrayscale()) return;

    histoEq* eq = new histoEq(img, imgB, ui.label_img2);
    eq->show();
    delete eq;
}

void editor::addSaltPepper() {
    if (!img.isGrayscale()) return;

    slithice::add_salt_pepper(img, imgB);
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::media3x3() {
    float cte = 1.0f / 9.0f;
    float media[] = { cte, cte, cte, cte, cte, cte, cte, cte, cte };
    slithice::convolution(img, media, 3, 3, imgB);
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::mediana3x3() {
    slithice::median_filter(img, 3, 3, imgB);
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::binariza() {
    imgB = QImage(img.width(), img.height(), QImage::Format_Grayscale8);
    slithice::binarize(img, imgB);
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::laplaciano() {
    float laplaciano[] = { 0, -1, 0, -1, 4, -1, 0, -1, 0};
    slithice::convolution(img, laplaciano, 3, 3, [](int *v) { *v = std::abs( * v) / 8; }, imgB);
    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::sobel() {
    int w = img.width(), h = img.height();
    // Não há vazamento de memória.
    // dx, dy e mag são excluídos pelo destrutor de SobelWindow.
    int* dx = new int[w * h], *dy = new int[w * h], *mag = new int[w * h], i, j, max = -256, min = 256;
    slithice::sobel(img, dx, dy, mag, imgB);

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));

    SobelWindow* sw = new SobelWindow(this, imgB, mag, dx, dy);
    sw->show();
}

void editor::drc() {
    QDialog* dialog = new QDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose, true);
    Ui::dsc_ui uid;
    uid.setupUi(dialog);

    connect(uid.okButton, &QPushButton::clicked, this, [=]() {
        imgB = QImage(img.width(), img.height(), QImage::Format_Grayscale8);
        slithice::dynamic_range_compression(img, uid.cSpinBox->value(), uid.gSpinBox->value(), imgB);
        ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
    });

    dialog->show();
}

void editor::limiariza() {
    QDialog* dialog = new QDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose, true);
    Ui::ui_lim uid;
    uid.setupUi(dialog);
    connect(uid.okButton, &QPushButton::clicked, this, [=](void) {
        slithice::thresholding(img, uid.spinBox->value(), imgB);
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
    if (img.allGray() || img.isGrayscale()) {
        img = img.convertToFormat(QImage::Format_Grayscale8);
        ui.menuOperacoes_img_colorida->setEnabled(false);
        ui.menu_Operacoes->setEnabled(true);
    }
    ui.label_img1->setFixedSize(img.width(), img.height());
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