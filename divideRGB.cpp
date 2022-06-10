#include "divideRGB.h"
#include <QDebug>

divideRGB::divideRGB(const QImage &img, QWidget* parent) {
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose, true);

	QImage aux = img;
	if (img.isGrayscale())
		aux = img.convertToFormat(QImage::Format_RGB32);

	// copia apenas para terem algum dado, e o mesmo tamanho
	QImage red = aux.copy(), green = aux.copy(), blue = aux.copy();
	// desassocia as cópias (previne mudanças na imagem original)
	red.detach();
	green.detach();
	blue.detach();

	QRgb* redBits = nullptr, * greenBits = nullptr, * blueBits = nullptr;
	for (int j = 0; j < img.height(); j++) {
		redBits = (QRgb*)(red.scanLine(j));
		greenBits = (QRgb*)(green.scanLine(j));
		blueBits = (QRgb*)(blue.scanLine(j));
		for (int i = 0; i < img.width(); i++) {
			redBits[i] &= 0xffff0000;
			greenBits[i] &= 0xff00ff00;
			blueBits[i] &= 0xff0000ff;
		}
	}
	
	// Imprimindo (colocando nos pixmaps/labels)
	ui.imgL1->setPixmap(QPixmap::fromImage(red));
	ui.imgL2->setPixmap(QPixmap::fromImage(green));
	ui.imgL3->setPixmap(QPixmap::fromImage(blue));
}