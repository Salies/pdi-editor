#include "divideRGB.h"
#include <QDebug>

divideRGB::divideRGB(const QImage &img, QWidget* parent) {
	ui.setupUi(this);

	QImage aux = img;
	if (img.isGrayscale())
		aux = img.convertToFormat(QImage::Format_ARGB32);
	// copia apenas para terem algum dado, e o mesmo tamanho
	QImage red = aux.copy(), green = aux.copy(), blue = aux.copy();
	red.detach();
	green.detach();
	blue.detach();
	uchar* redBits = red.bits(), * greenBits = green.bits(), * blueBits = blue.bits();
	for (int i = 0; i < (img.width() * img.height() * 4); i += 4)
	{
		// bits[i] = azul
		// bits[i + 1] = verde
		// bits [i + 2] = vermelho
		// imagem azul
		blueBits[i + 1] = 0;
		blueBits[i + 2] = 0;

		// imagem verde
		greenBits[i] = 0;
		greenBits[i + 2] = 0;

		// imagem vermelha
		redBits[i] = 0;
		redBits[i + 1] = 0;
	}
	
	// Imprimindo (colocando nos pixmaps/labels)
	ui.imgL1->setPixmap(QPixmap::fromImage(red));
	ui.imgL2->setPixmap(QPixmap::fromImage(green));
	ui.imgL3->setPixmap(QPixmap::fromImage(blue));
}