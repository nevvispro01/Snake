#include "snake.h"
#include <QPainter>
#include <QKeyEvent>
#include <utility>



Snake::Snake(QObject *parent) : QObject(parent),
                                QGraphicsItem()
{
    setFlag(QGraphicsItem::ItemIsFocusable);

//    array_moving.resize(1000);
    array_moving.push_back(std::pair<QPointF, Move>(QPointF(0, 25), Move::DOWN));
    array_moving.push_back(std::pair<QPointF, Move>(QPointF(0, 25), Move::DOWN));

    auto body = new Body();
    body->setParentItem(this);
    body->moveBy(0, -25);
    array_body.push_back(body);

    body = new Body();
    body->setParentItem(this);
    body->moveBy(0, -50);
    array_body.push_back(body);
}


void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (player) {
    case Player::PLAYER_ONE:
        painter->fillRect(boundingRect(), QBrush(Qt::blue));
        painter->setPen(Qt::blue);
        painter->drawRect(boundingRect());
        break;
    case Player::PLAYER_TWO:
        painter->fillRect(boundingRect(), QBrush(Qt::red));
        painter->setPen(Qt::red);
        painter->drawRect(boundingRect());
        break;
    case Player::PLAYER_THREE:
        painter->fillRect(boundingRect(), QBrush(Qt::green));
        painter->setPen(Qt::green);
        painter->drawRect(boundingRect());
        break;
    }


}

QRectF Snake::boundingRect() const
{
    return {0,0,25,25};
}

void Snake::PressKey(QKeyEvent *event)
{
    switch (player) {
    case Player::PLAYER_ONE:{
        if (event->key() == Qt::Key_W and move != Move::DOWN){
            current_move = Move::UP;
        }else if (event->key() == Qt::Key_S and move != Move::UP){
            current_move = Move::DOWN;
        }else if (event->key() == Qt::Key_A and move != Move::RIGHT){
            current_move = Move::LEFT;
        }else if (event->key() == Qt::Key_D and move != Move::LEFT){
            current_move = Move::RIGHT;
        }
        break;
    }
    case Player::PLAYER_TWO:{
        if (event->key() == Qt::Key_Up and move != Move::DOWN){
            current_move = Move::UP;
        }else if (event->key() == Qt::Key_Down and move != Move::UP){
            current_move = Move::DOWN;
        }else if (event->key() == Qt::Key_Left and move != Move::RIGHT){
            current_move = Move::LEFT;
        }else if (event->key() == Qt::Key_Right and move != Move::LEFT){
            current_move = Move::RIGHT;
        }
        break;
    }
    case Player::PLAYER_THREE:{
        if (event->key() == Qt::Key_I and move != Move::DOWN){
            current_move = Move::UP;
        }else if (event->key() == Qt::Key_K and move != Move::UP){
            current_move = Move::DOWN;
        }else if (event->key() == Qt::Key_J and move != Move::RIGHT){
            current_move = Move::LEFT;
        }else if (event->key() == Qt::Key_L and move != Move::LEFT){
            current_move = Move::RIGHT;
        }
        break;
    }

    }

}

void Snake::Moving()
{
    move = current_move;
    switch (move) {
    case Move::UP:
        moveBy(0, -25);
        array_moving.insert(array_moving.begin(), std::pair<QPointF, Move>(QPointF(0, -25), move));
        break;
    case Move::DOWN:
        moveBy(0, 25);
        array_moving.insert(array_moving.begin(), std::pair<QPointF, Move>(QPointF(0, 25), move));
        break;
    case Move::LEFT:
        moveBy(-25, 0);
        array_moving.insert(array_moving.begin(), std::pair<QPointF, Move>(QPointF(-25, 0), move));
        break;
    case Move::RIGHT:
        moveBy(25, 0);
        array_moving.insert(array_moving.begin(), std::pair<QPointF, Move>(QPointF(25, 0), move));
        break;

    }

    auto i{1};
    for (auto & elem : array_body){

        switch (move) {
        case Move::UP:
            elem->moveBy(0, 25);
            break;
        case Move::DOWN:
            elem->moveBy(0, -25);
            break;
        case Move::LEFT:
            elem->moveBy(25, 0);
            break;
        case Move::RIGHT:
            elem->moveBy(-25, 0);
            break;
        }
        elem->moveBy(array_moving.at(i).first.x(), array_moving.at(i).first.y());
        elem->set_move(array_moving.at(i).second);
        ++i;
    }
}

void Snake::create_body()
{
    auto body = new Body();

    switch (array_body.back()->get_move()) {
    case Move::UP:{

        body->setParentItem(this);
        body->setPos(array_body.back()->pos().x(), array_body.back()->pos().y() + 25);
        array_body.push_back(body);
        break;
    }
    case Move::DOWN:{

        body->setParentItem(this);
        body->setPos(array_body.back()->pos().x(), array_body.back()->pos().y() - 25);
        array_body.push_back(body);
        break;
    }
    case Move::LEFT:{

        body->setParentItem(this);
        body->setPos(array_body.back()->pos().x() + 25, array_body.back()->pos().y());
        array_body.push_back(body);
        break;
    }
    case Move::RIGHT:{

        body->setParentItem(this);
        body->setPos(array_body.back()->pos().x() - 25, array_body.back()->pos().y());
        array_body.push_back(body);
        break;
    }

    }
}

void Snake::set_player(Player player_)
{
    player = player_;
}

Player Snake::get_player()
{
    return player;
}
