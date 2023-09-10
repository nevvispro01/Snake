#ifndef BODY_H
#define BODY_H

#include <QObject>
#include <QGraphicsItem>

enum class Move{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Body : public QGraphicsItem
{

public:
    Body();

    void set_move(Move move_);

    Move get_move();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;

    Move move{Move::DOWN};
};

#endif // BODY_H
