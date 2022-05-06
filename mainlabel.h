#pragma once
#include <QLabel>
#include <QMouseEvent>

class MainLabel :
    public QLabel
{
    Q_OBJECT
public:
    MainLabel();
private:
    virtual void mouseMoveEvent(QMouseEvent* event);
signals:
    void novaPos(int x, int y);
};

