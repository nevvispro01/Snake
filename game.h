#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "snake.h"

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    void start_game();

signals:

    void go_to_main_menu();

private:

    void add_score(Player player_);
    Ui::Game *ui;
};

#endif // GAME_H
