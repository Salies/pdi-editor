#include "conv_hsl.h"
#include <algorithm>
#include <cmath>
#include <QDebug>

conv_hsl::conv_hsl(QWidget* parent) {
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose, true);

	mostraCor = new QWidget();
	mostraCor->setAutoFillBackground(true);
	mostraCor->setFixedSize(230, 20);
	mostraCor->setPalette(QPalette(QColor(0, 0, 0)));

	ui.gridLayout->addWidget(mostraCor, 4, 0, 1, 4);

	int r = 164, g = 235, b = 255, h = -1, s = -1, l = -1;
	RGBtoHSL(r, g, b, &h, &s, &l);
	qDebug() << h << s << l;
	r = -1; g = -1; b = -1;
	HSLtoRGB(h, s, l, &r, &g, &b);
	qDebug() << r << g << b;
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


float conv_hsl::f(int n, float H, float S, float L) {
	float k = std::fmod((n + (H / 30.0f)), 12.0f);
	float a = S * std::min(L, 1.0f - L);
	return std::round((L - a * std::max(-1.0f, std::min({ k - 3.0f, 9.0f - k, 1.0f })))*255.0f);
}

// TODO: tentar melhorar pro caso de teste RGB(164, 235, 255)
// Fórmula parcialmente usada: https://www.rapidtables.com/convert/color/hsl-to-rgb.html
void conv_hsl::HSLtoRGB(int h, int s, int l, int* r, int* g, int* b) {
	// Imagem sem saturação alguma (ou seja, preta)
	if (s == 0) {
		*r = *g = *b = 0;
		return;
	}

	float hh = (h / 2.0f) * 3.0f, ss = s / 240.0f, ll = l / 240.0f, rr = 0, gg = 0, bb = 0;

	*r = f(0, hh, ss, ll);
	*g = f(8, hh, ss, ll);
	*b = f(4, hh, ss, ll);
}
