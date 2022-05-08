#include "histoEq.h"

histoEq::histoEq(const QImage& img, QImage *imgSaida, QLabel* labelSaida, QWidget* parent) {
	setAttribute(Qt::WA_DeleteOnClose, true);
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &histoEq::eq);
	barra = new QwtPlotBarChart;
	barra->setSpacing(0);
	barra->attach(ui.histoPlot);
	ui.histoPlot->setAxisScale(ui.histoPlot->xBottom, 0, 255, 51);
	ui.histoPlot->setAxisScale(ui.histoPlot->xTop, 0, 255, 51);
	h.reserve(256);
	h.resize(256);
	std::fill(h.begin(), h.end(), 0);

	// Histograma
	const uchar* bits = img.constBits();
	for (int i = 0; i < (img.width() * img.height()); i++)
		h[bits[i]]++;
	plot();

	// Preparando para uma possível equalização
	*imgSaida = img.copy();
	img_eq = imgSaida;
	label_eq = labelSaida;
}

void histoEq::eq() {
	int freq_acc = 0, size = img_eq->width() * img_eq->height(), i;
	uchar* lut = new uchar[256]; // lookup table para economizar processamento
	float escala = 255.0f / size;

	for (i = 0; i < 256; i++) {
		freq_acc += h[i];
		lut[i] = (uchar)(freq_acc * escala);
	}

	uchar* bits = img_eq->bits();
	std::fill(h.begin(), h.end(), 0);
	for (i = 0; i < size; i++) {
		bits[i] = lut[bits[i]];
		h[bits[i]]++;
	}
	plot();

	label_eq->setPixmap(QPixmap::fromImage(*img_eq));
}

void histoEq::plot() {
	barra->setSamples(QVector<double>::fromStdVector(h));
	ui.histoPlot->replot();
}