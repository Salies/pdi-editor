#include "histoEq.h"

histoEq::histoEq(const QImage& img, QImage *imgSaida, QLabel* labelSaida, QWidget* parent) {
	setAttribute(Qt::WA_DeleteOnClose, true);
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &histoEq::eq);
	int w = img.width(), h = img.height();
	ui.fromWidth->setMaximum(w);
	ui.toWidth->setMaximum(w);
	ui.fromHeight->setMaximum(h);
	ui.toHeight->setMaximum(h);
	ui.toWidth->setValue(w);
	ui.toHeight->setValue(h);

	// Histograma
	const uchar* bits = img.constBits();
	// Formato double é necessário para plotar
	double histograma[256] = { 0 };
	for (int i = 0; i < (w * h); i++)
		histograma[bits[i]]++;

	// Para plotar, é necessária a conversão: double[] -> QVector
	vec.reserve(256);
	std::copy(histograma, histograma + 256, std::back_inserter(vec));

	barra = new QwtPlotBarChart;
	barra->setSamples(vec);
	barra->setSpacing(0);
	barra->attach(ui.histoPlot);
	ui.histoPlot->setAxisScale(ui.histoPlot->xBottom, 0, 255, 51);
	ui.histoPlot->setAxisScale(ui.histoPlot->xTop, 0, 255, 51);
	
	// Preparando para uma possível equalização
	*imgSaida = img.copy();
	img_eq = imgSaida;
	label_eq = labelSaida;
}

void histoEq::eq() {
	int fromWidth = ui.fromWidth->value(), toWidth = ui.toWidth->value(),
		fromHeight = ui.fromHeight->value(), toHeight = ui.toHeight->value(),
		freq_acc = 0, i;
	uchar* lut = new uchar[256]; // lookup table para economizar processamento
	float escala = 255.0f / ((toWidth - fromWidth) * (toHeight - fromHeight));

	for (i = 0; i < 256; i++) {
		freq_acc += vec[i];
		lut[i] = (uchar)(freq_acc * escala);
	}

	uchar* bits = img_eq->bits();
	for (i = 0; i < (toWidth * toHeight); i++) {
		bits[i] = lut[bits[i]];
	}




	label_eq->setPixmap(QPixmap::fromImage(*img_eq));
}