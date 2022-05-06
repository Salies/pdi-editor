#pragma once
#include <QWidget>
#include <ui_divideRGB.h>

class divideRGB :
    public QWidget
{
    Q_OBJECT
public:
    divideRGB(const QImage& img, QWidget* parent = Q_NULLPTR);
private:
    Ui::dividergb_class ui;
};

