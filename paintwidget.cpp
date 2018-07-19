#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
    this->pic = new QPixmap("/Users/superchen/Desktop/ScreenShot/route.png");
    if(pic->isNull())
        qDebug()<<"failed to load image";
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter pen;
    pen.begin(this);
    pen.drawImage(0,0,pic->toImage());
    //pen.drawRect(20,20,10,50);
    pen.end();
}
