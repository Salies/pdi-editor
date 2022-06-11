#pragma once

#include <ui_conv_hsl.h>
     
class conv_hsl : public QWidget
{
    Q_OBJECT

public:
    conv_hsl(QWidget *parent = Q_NULLPTR);

private:
    Ui::conv_hsl_class ui;
    QWidget mostraCor;

private slots:
    void convertRGBtoHSL();
    void convertHSLtoRGB();
};
