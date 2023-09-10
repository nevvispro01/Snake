#include "eat.h"
#include <QPainter>

Eat::Eat()
{

}

void Eat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(QBrush(Qt::red));
//    painter->setPen(QPen(Qt::red));
//    painter->drawArc(boundingRect(), 0, 16*360);
    QPainterPath path;
    path.addEllipse(boundingRect());
    painter->fillPath(path, QBrush(Qt::darkGreen));
}

QRectF Eat::boundingRect() const
{
    return {0,0,25,25};
}
