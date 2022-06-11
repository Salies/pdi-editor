#include "divideRGB.h"
#include "slithice/slithice.h"

divideRGB::divideRGB(const QImage &img, QWidget* parent) {
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose, true);

	QImage aux = img;
	if (img.isGrayscale())
		aux = img.convertToFormat(QImage::Format_RGB32);

	// copia apenas para terem algum dado, e o mesmo tamanho
	QImage red = QImage(img.width(), img.height(), QImage::Format_RGB32),
		green = QImage(img.width(), img.height(), QImage::Format_RGB32),
		blue = QImage(img.width(), img.height(), QImage::Format_RGB32);

	slithice::split_rgb(aux, red, green, blue);
	
	// Imprimindo (colocando nos pixmaps/labels)
	ui.imgL1->setPixmap(QPixmap::fromImage(red));
	ui.imgL2->setPixmap(QPixmap::fromImage(green));
	ui.imgL3->setPixmap(QPixmap::fromImage(blue));
}