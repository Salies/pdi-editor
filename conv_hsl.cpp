#include "conv_hsl.h"
#include <algorithm>
#include <cmath>
#include <QDebug>

conv_hsl::conv_hsl(QWidget* parent) {
	ui.setupUi(this);
	setWindowModality(Qt::ApplicationModal);
	setAttribute(Qt::WA_DeleteOnClose, true);

	mostraCor = new QWidget();
	mostraCor->setAutoFillBackground(true);
	mostraCor->setFixedSize(230, 20);
	mostraCor->setPalette(QPalette(QColor(0, 0, 0)));

	ui.gridLayout->addWidget(mostraCor, 4, 0, 1, 4);

	connect(ui.buttonToRGB, &QPushButton::clicked, this, &conv_hsl::convertHSLtoRGB);
	connect(ui.buttonToHSL, &QPushButton::clicked, this, &conv_hsl::convertRGBtoHSL);
}

// Fórmula usada: https://www.rapidtables.com/convert/color/rgb-to-hsl.html
void conv_hsl::RGBtoHSL(int r, int g, int b, int* h, int* s, int* l) {
	float rr, gg, bb, cmax, cmin, delta, hh = 0, ll = 0;
	rr = r / 255.0f;
	gg = g / 255.0f;
	bb = b / 255.0f;
	cmax = std::max({ rr, gg, bb });
	cmin = std::min({ rr, gg, bb });
	ll = (cmax + cmin) / 2.0f;
	if (cmax == cmin)
		*h = *s = 0;
	// Calcula H e S
	else {
		float delta = cmax - cmin;
		// S está na escala de 0...1, converter p/ 240
		*s = std::round((delta / (1.0f - std::abs((2 * ll) - 1.0f))) * 240.f);
		if (cmax == rr)
			hh = ((gg - bb) / delta) + (gg < bb ? 6.0f : 0.0f);
		else if (cmax == gg)
			hh = ((bb - rr) / delta) + 2.0f;
		else if (cmax == bb)
			hh = ((rr - gg) / delta) + 4.0f;

		if (hh < 0.0f)
			hh += 360.f;
		hh *= 60.0f;
		// h foi dado na escala 360, converter para 240
		// já arredonda para depois converter p/ inteiro
		// lembrando que o valor nunca vai chegar a 240
		// pois na escala de 360 ele nunca chega a 360 (0 <= H < 360)
		hh = std::round((hh * 2.0f) / 3.0f);
		*h = hh;
	}
	// Calcula L
	*l = std::round(ll * 240.0f);
}


// HSL para RGB
// Fórmula usada: https://en.wikipedia.org/wiki/HSL_and_HSV ("HSL to RGB alternative")
// Ia tentar melhorar pro caso de teste RGB(164, 235, 255)
// mas não precisa, o próprio Paint é impreciso neste caso
// (dá o mesmo resultado pra 234 e 235)
float conv_hsl::f(int n, float H, float S, float L) {
	float k = std::fmod((n + (H / 30.0f)), 12.0f);
	return std::round((L - (S * std::min(L, 1.0f - L)) * std::max(-1.0f, std::min({ k - 3.0f, 9.0f - k, 1.0f }))) * 255.0f);
}

void conv_hsl::HSLtoRGB(int h, int s, int l, int* r, int* g, int* b) {
	// Imagem sem saturação alguma (ou seja, preta)
	float ll = l / 240.0f;
	if (s == 0) {
		*r = *g = *b = std::round(ll * 255.0f);
		return;
	}

	float hh = (h / 2.0f) * 3.0f, ss = s / 240.0f, rr = 0, gg = 0, bb = 0;

	*r = f(0, hh, ss, ll);
	*g = f(8, hh, ss, ll);
	*b = f(4, hh, ss, ll);
}

void conv_hsl::convertRGBtoHSL() {
	int h, s, l, r = ui.spinR->value(), g = ui.spinG->value(), b = ui.spinB->value();
	mostraCor->setPalette(QPalette(QColor(r, g, b)));
	RGBtoHSL(r, g, b, &h, &s, &l);
	ui.spinH->setValue(h);
	ui.spinS->setValue(s);
	ui.spinL->setValue(l);
}

void conv_hsl::convertHSLtoRGB() {
	int r, g, b;
	HSLtoRGB(ui.spinH->value(), ui.spinS->value(), ui.spinL->value(), &r, &g, &b);
	mostraCor->setPalette(QPalette(QColor(r, g, b)));
	ui.spinR->setValue(r);
	ui.spinG->setValue(g);
	ui.spinB->setValue(b);
}