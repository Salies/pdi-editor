#pragma once
#include <QWidget>
#include <ui_divideRGB.h>

class divideRGB :
    public QWidget
{
    Q_OBJECT
public:
    divideRGB(QImage *img);
private:
    Ui::dividergb_class ui;
};

