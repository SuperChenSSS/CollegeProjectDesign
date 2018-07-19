#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <Qpainter>
#include <QDebug>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    QPixmap *pic = 0;
signals:

public slots:
};

#endif // PAINTWIDGET_H
