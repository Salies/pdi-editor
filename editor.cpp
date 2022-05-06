#include "editor.h"
#include "sobre.h"
#include "divideRGB.h"
#include <QFileDialog>

#include<QDebug>

editor::editor(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Conexões (coneta a ação do menu/botões a uma função)
    connect(ui.pushButton, &QPushButton::clicked, this, &editor::copiaParaEsquerda);
    connect(ui.action_Abrir, &QAction::triggered, this, &editor::abrir);
    connect(ui.action_paraCinza, &QAction::triggered, this, &editor::converteParaCinza);
    connect(ui.actionDividir_RGB, &QAction::triggered, this, &editor::dividirRGB);
    connect(ui.actionSobre, &QAction::triggered, this, &editor::janelaSobre);
    connect(ui.actionInverte_cinza, &QAction::triggered, this, &editor::inverteCinza);
}

void editor::abrir() {
    QString arquivoEscolhido = QFileDialog::getOpenFileName(
        this, tr("Abrir imagem"), "", tr("Bitmap (*bmp);;Todos os arquivos (*)")
    );
    img.load(arquivoEscolhido);
    qDebug() << img.isGrayscale();
    qDebug() << img.pixelColor(0, 0);
    ui.label_img1->setPixmap(QPixmap::fromImage(img));
}

void editor::copiaParaEsquerda() {
    img = imgB.copy();
    ui.label_img1->setPixmap(*ui.label_img2->pixmap());
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

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::inverteCinza() {
    imgB = img.copy();
    int cinza;
    for (int i = 0; i < img.width(); i++) {
        for (int j = 0; j < img.height(); j++) {
            cinza = 255 - img.pixelColor(i, j).red();
            imgB.setPixelColor(i, j, QColor(cinza, cinza, cinza));
        }
    }

    ui.label_img2->setPixmap(QPixmap::fromImage(imgB));
}

void editor::inverteColorido() {

}

void editor::dividirRGB() {
    divideRGB* d = new divideRGB(img);
    d->show();
}

// Ajuda
void editor::janelaSobre() {
    sobre *s = new sobre();
    s->show();
}

// TODO STRETCHER