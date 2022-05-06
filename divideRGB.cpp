#include "divideRGB.h"

divideRGB::divideRGB(QImage img) {
	ui.setupUi(this);

	// Divindindo a imagem para os três canais
	QColor cor;
	// copia apenas para terem algum dado, e o mesmo tamanho
	QImage red = img, green = img, blue = img;
	for (int i = 0; i < img.width(); i++) {
		for (int j = 0; j < img.height(); j++) {
			cor = img.pixelColor(i, j);
			red.setPixelColor(i, j, QColor(cor.red(), 0, 0));
			green.setPixelColor(i, j, QColor(0, cor.green(), 0));
			blue.setPixelColor(i, j, QColor(0, 0, cor.blue()));
		}
	}
	
	// Imprimindo (colocando nos pixmaps/labels)
	ui.imgL1->setPixmap(QPixmap::fromImage(red));
	ui.imgL2->setPixmap(QPixmap::fromImage(green));
	ui.imgL3->setPixmap(QPixmap::fromImage(blue));
}