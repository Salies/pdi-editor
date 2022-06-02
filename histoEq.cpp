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
	const uchar* bits = nullptr;
	for (int j = 0; j < img.height(); j++) {
		bits = img.constScanLine(j); // abuso de notação
		for (int i = 0; i < img.width(); i++)
			h[bits[i]]++;
	}
	plot();

	// Preparando para uma possível equalização
	*imgSaida = img.copy();
	img_eq = imgSaida;
	label_eq = labelSaida;
}

void histoEq::eq() {
	int freq_acc = 0, width = img_eq->width(), height = img_eq->height(), i;
	uchar* lut = new uchar[256]; // lookup table para economizar processamento
	float escala = 255.0f / (width * height);

	for (i = 0; i < 256; i++) {
		freq_acc += h[i];
		lut[i] = std::max(0, (uchar)(freq_acc * escala) - 1);
	}

	uchar* bits = nullptr;
	std::fill(h.begin(), h.end(), 0);
	for (int j = 0; j < height; j++) {
		bits = img_eq->scanLine(j);
		for (i = 0; i < width; i++) {
			bits[i] = lut[bits[i]];
			h[bits[i]]++;
		}
	}
	plot();

	label_eq->setPixmap(QPixmap::fromImage(*img_eq));
}

void histoEq::plot() {
	barra->setSamples(QVector<double>::fromStdVector(h));
	ui.histoPlot->replot();
}