#ifndef GRAPHICS_SCENE_H
#define GRAPHICS_SCENE_H

#include <QGraphicsScene>
#include <QTimer>

#include "snake.h"
#include "eat.h"

class Graphics_scene : public QGraphicsScene
{

    Q_OBJECT
public:
    Graphics_scene(QObject *parent = nullptr);

    void start_stop_game(bool value);

protected:

    void keyPressEvent(QKeyEvent *keyEvent) override;

public slots:

    void slot_timer();

    void slot_timer_eat();

signals:

    void add_score(Player player_);
    void exit_game();

private:
    QTimer * timer{new QTimer};
    QTimer * timer_eat{new QTimer};

    QTimer * timer_srart_game{new QTimer};
    QGraphicsTextItem *text;

    int time_rand;

    Snake *snake1{new Snake};
    Snake *snake2{new Snake};
    Snake *snake3{new Snake};

    std::vector<Eat * > array_eat;
};

#endif // GRAPHICS_SCENE_H
