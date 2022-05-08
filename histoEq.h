#pragma once
#include <QWidget>
#include <QImage>
#include <ui_histoEq.h>
#include <qwt_plot_barchart.h>

class histoEq :
    public QWidget
{
    Q_OBJECT
public:
    histoEq(const QImage& img, QImage* imgSaida, QLabel *labelSaida, QWidget* parent = Q_NULLPTR);
private:
    Ui::histoEq ui;
    void eq();
    QVector<double> vec;
    QImage *img_eq;
    QLabel* label_eq;
    QwtPlotBarChart* barra;
};

