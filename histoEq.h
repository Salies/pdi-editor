#pragma once
#include <QWidget>
#include <QImage>
#include <ui_histoEq.h>

class histoEq :
    public QWidget
{
    Q_OBJECT
public:
    histoEq(QImage* img, QWidget* parent = Q_NULLPTR);
private:
    Ui::histoEq ui;
};

