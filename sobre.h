#pragma once

#include <QDialog>
#include "ui_sobre.h"

class sobre : public QDialog {
	Q_OBJECT
public:
	sobre() {
		ui.setupUi(this);
		setAttribute(Qt::WA_DeleteOnClose, true);
	}
private:
	Ui::Sobre ui;
};