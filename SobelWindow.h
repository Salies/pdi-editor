#pragma once
#include <QWidget>
#include <ui_sobelwindow.h>

class SobelWindow :
    public QWidget
{
    Q_OBJECT
public:
    SobelWindow(QWidget* parent, const QImage& img, int* _mag, int* _dx, int* _dy);
    ~SobelWindow();
private:
    int* mag, * dx, * dy, w, h;
    Ui::ui_sobelwindow ui;
private slots:
    void moveu(int x, int y);
};

