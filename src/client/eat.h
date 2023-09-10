#ifndef EAT_H
#define EAT_H
#include <QGraphicsItem>

class Eat : public QGraphicsItem
{
public:
    Eat();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;
};

#endif // EAT_H
