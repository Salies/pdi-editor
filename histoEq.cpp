#include "histoEq.h"
#include "slithice/slithice.h"

histoEq::histoEq(const QImage& img, QImage &imgSaida, QLabel* labelSaida, QWidget* parent) {
	setAttribute(Qt::WA_DeleteOnClose, true);
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &histoEq::eq);
	barra.setSpacing(0);
	barra.attach(ui.histoPlot);
	ui.histoPlot->setAxisScale(ui.histoPlot->xBottom, 0, 255, 51);
	ui.histoPlot->setAxisScale(ui.histoPlot->xTop, 0, 255, 51);

	slithice::build_histogram(img, h);
	plot();

	// Preparando para uma possível equalização
	imgSaida = img.copy();
	imgSaida.detach();
	img_eq = imgSaida;
	label_eq = labelSaida;
}

void histoEq::eq() {
	slithice::eq_histogram(img_eq, h);
	plot();
	label_eq->setPixmap(QPixmap::fromImage(img_eq));
}

void histoEq::plot() {
	barra.setSamples(QVector<double>::fromStdVector(h));
	ui.histoPlot->replot();
}