#include "SobelWindow.h"
#include "mainlabel.h"

#include <QDebug>

SobelWindow::~SobelWindow() {
	delete dx;
	delete dy;
	delete mag;
}

SobelWindow::SobelWindow(QWidget* parent, const QImage &img, int* _mag, int* _dx, int* _dy) {
	setAttribute(Qt::WA_DeleteOnClose, true);
	ui.setupUi(this);
	mag = _mag;
	dx = _dx;
	dy = _dy;
	w = img.width();
	h = img.height();
	ui.label->setFixedSize(w, h);
	ui.label->setPixmap(QPixmap::fromImage(img));
	connect(ui.label, &MainLabel::novaPos, this, &SobelWindow::moveu);
}

void SobelWindow::moveu(int x, int y) {
	// Não vale para as bordas
	if (x == 0 || y == 0 || x == w - 1 || y == h - 1) {
		ui.mag->setText(">> borda <<");
		return;
	}

	ui.mag->setText("<b>mag:</b> " + QString::number(mag[(w * y) + x]));
}