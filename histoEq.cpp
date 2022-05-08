#include "histoEq.h"
#include <QDebug>

histoEq::histoEq(QImage* img, QWidget* parent) {
	setAttribute(Qt::WA_DeleteOnClose, true);
	ui.setupUi(this);

	qDebug() << "eae!";
	qDebug() << "formato da imagem" << img->format();

	uchar* bits = img->bits();
	int histograma[256] = { 0 };
	/*for (int i = 0; i < (img->width() * img->height()); i++) {
		histograma[bits[i]]++;
	qDebug() << histograma[30];*/
}