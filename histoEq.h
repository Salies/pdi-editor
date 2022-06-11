#pragma once
#include <QWidget>
#include <QImage>
#include <QLabel>
#include <ui_histoEq.h>
#include <qwt_plot_barchart.h>

class histoEq :
    public QWidget
{
    Q_OBJECT
public:
    histoEq(const QImage& img, QImage &imgSaida, QLabel *labelSaida, QWidget* parent = Q_NULLPTR);
private:
    Ui::histoEq ui;
    void eq();
    void plot();
    std::vector<double> h; // formato double é necessário para plotar
    QImage img_eq;
    QLabel* label_eq;
    QwtPlotBarChart barra;
};

