#include "mainlabel.h"

MainLabel::MainLabel() {
	setMouseTracking(true);
}

void MainLabel::mouseMoveEvent(QMouseEvent* event) {
	novaPos(event->x(), event->y());
}
