#include "histoEq.h"
#include <QDebug>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QList>
#include <list>
#include <QDateTime>
#include <QLineSeries>
#include <QDateTimeAxis>

#include <qwt_plot_barchart.h>

histoEq::histoEq(QImage* img, QWidget* parent) {
	setAttribute(Qt::WA_DeleteOnClose, true);
	ui.setupUi(this);

	uchar* bits = img->bits();
	// Formato double é necessário para plotar
	double histograma[256] = { 0 };
	for (int i = 0; i < (img->width() * img->height()); i++)
		histograma[bits[i]]++;

	// Para plotar, é necessária a conversão: double[] -> QVector
	QVector<double> vec;
	vec.reserve(256);
	std::copy(histograma, histograma + 256, std::back_inserter(vec));

	QwtPlotBarChart* barra = new QwtPlotBarChart;
	barra->setSamples(vec);
	barra->setSpacing(0);
	barra->attach(ui.histoPlot);
	ui.histoPlot->setAxisScale(ui.histoPlot->xBottom, 0, 256, 64);
	ui.histoPlot->setAxisScale(ui.histoPlot->xTop, 0, 256, 64);
}