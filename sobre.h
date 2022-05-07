#pragma once

#include <QWidget>
#include "ui_sobre.h"

class sobre : public QWidget {
	Q_OBJECT
public:
	sobre() {
		ui.setupUi(this);
		setAttribute(Qt::WA_DeleteOnClose, true);
	}
private:
	Ui::Sobre ui;
};