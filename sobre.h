#pragma once

#include <QWidget>
#include "ui_sobre.h"

class sobre : public QWidget {
	Q_OBJECT
public:
	sobre() {
		ui.setupUi(this);
	}
private:
	Ui::Sobre ui;
};