#include "mainlabel.h"
#include <QDebug>

MainLabel::MainLabel() {
	setMouseTracking(true);
}

void MainLabel::mouseMoveEvent(QMouseEvent* event) {
	novaPos(event->x(), event->y());
}
