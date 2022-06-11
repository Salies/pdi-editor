#include "conv_hsl.h"
#include "slithice/slithice.h"
#include <algorithm>

conv_hsl::conv_hsl(QWidget* parent) {
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose, true);

	mostraCor.setAutoFillBackground(true);
	mostraCor.setFixedSize(230, 20);
	mostraCor.setPalette(QPalette(QColor(0, 0, 0)));

	ui.gridLayout->addWidget(&mostraCor, 4, 0, 1, 4);

	connect(ui.buttonToRGB, &QPushButton::clicked, this, &conv_hsl::convertHSLtoRGB);
	connect(ui.buttonToHSL, &QPushButton::clicked, this, &conv_hsl::convertRGBtoHSL);
}

void conv_hsl::convertRGBtoHSL() {
	uchar h, s, l, r = ui.spinR->value(), g = ui.spinG->value(), b = ui.spinB->value();
	mostraCor.setPalette(QPalette(QColor(r, g, b)));
	slithice::rgb_to_hsl(r, g, b, &h, &s, &l);
	ui.spinH->setValue(h);
	ui.spinS->setValue(s);
	ui.spinL->setValue(l);
}

void conv_hsl::convertHSLtoRGB() {
	uchar r, g, b;
	slithice::hsl_to_rgb(ui.spinH->value(), ui.spinS->value(), ui.spinL->value(), &r, &g, &b);
	mostraCor.setPalette(QPalette(QColor(r, g, b)));
	ui.spinR->setValue(r);
	ui.spinG->setValue(g);
	ui.spinB->setValue(b);
}