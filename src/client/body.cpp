#include "body.h"
#include <QPainter>
#include <snake.h>

Body::Body() : QGraphicsItem()
{
}

void Body::set_move(Move move_)
{
    move = move_;
}

Move Body::get_move()
{
    return move;
}

void Body::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (static_cast<Snake *>(parentItem())->get_player()) {
    case Player::PLAYER_ONE:
        painter->setPen(Qt::blue);
        painter->drawRect(boundingRect());
        break;
    case Player::PLAYER_TWO:
        painter->setPen(Qt::red);
        painter->drawRect(boundingRect());
        break;
    case Player::PLAYER_THREE:
        painter->setPen(Qt::green);
        painter->drawRect(boundingRect());
        break;
    }

}

QRectF Body::boundingRect() const
{
    return {0,0,25,25};
}
