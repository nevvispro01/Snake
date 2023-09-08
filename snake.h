#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QGraphicsItem>
#include "body.h"


enum class Player{
    NONE,
    PLAYER_ONE,
    PLAYER_TWO,
    PLAYER_THREE
};

class Snake : public QObject,
              public QGraphicsItem

{

    Q_OBJECT
public:
    Snake(QObject *parent = nullptr);

    void PressKey(QKeyEvent *event);

    void Moving();

    void create_body();

    void set_player(Player player_);

    Player get_player();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;

private:

    std::vector<Body *> array_body;
    std::vector<std::pair<QPointF, Move>> array_moving;

    std::vector<Move> current_move{Move::DOWN};
    Move move{Move::DOWN};

    Player player{Player::NONE};
};

#endif // SNAKE_H
