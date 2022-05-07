#pragma once

#include <ui_conv_hsl.h>
     
class conv_hsl : public QWidget
{
    Q_OBJECT

public:
    conv_hsl(QWidget *parent = Q_NULLPTR);

private:
    Ui::conv_hsl_class ui;
    QWidget* mostraCor;

//private slots:
    void RGBtoHSL(int r, int g, int b, int* h, int* s, int* l);
    float f(int n, float H, float S, float L);
    void HSLtoRGB(int h, int s, int l, int *r, int *g, int *b);
};
