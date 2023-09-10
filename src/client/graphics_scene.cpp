#include "graphics_scene.h"

#include <QMessageBox>
#include <cstdlib>
#include <math.h>
#include <unistd.h>
#include "common.h"

Graphics_scene::Graphics_scene(QObject *parent) : QGraphicsScene(parent)
{

    text = new QGraphicsTextItem;
    text->setPos(sceneRect().width()/2, sceneRect().height()/2);
    addItem(text);

    addRect(QRectF(0,0,weight_,height_), QPen(Qt::gray));

    connect(timer, &QTimer::timeout, this, &Graphics_scene::slot_timer);

    connect(timer_eat, &QTimer::timeout, this, &Graphics_scene::slot_timer_eat);

    connect(timer_srart_game, &QTimer::timeout, [this]{

        if (text->toPlainText() == "3"){
            text->setPlainText("2");
        }else if (text->toPlainText() == "2"){
            text->setPlainText("1");
        }else{
            removeItem(text);
            timer_srart_game->stop();
        }


    });

    snake1->setPos(300, 250);
    snake1->set_player(Player::PLAYER_ONE);
    addItem(std::move(snake1));
    snake1->setSelected(true);

    snake2->setPos(225, 250);
    snake2->set_player(Player::PLAYER_TWO);
    addItem(std::move(snake2));
    snake2->setSelected(true);

//    snake3->setPos(150, 250);
//    snake3->set_player(Player::PLAYER_THREE);
//    addItem(std::move(snake3));
//    snake3->setSelected(true);
}

void Graphics_scene::keyPressEvent(QKeyEvent *keyEvent)
{
    auto elems = items();

    for (auto elem : elems){
        if (auto item{dynamic_cast<Snake *>(elem)};
                item){
            item->PressKey(keyEvent);
        }
    }

}

void Graphics_scene::start_stop_game(bool value)
{


    if (value){

        text->setPlainText("3");
        timer_srart_game->start(1000);

        timer->start(200);

        time_rand = std::rand() % 4;

        timer_eat->start(time_rand * 1000);
    }else{
        timer->stop();

        timer_eat->stop();
    }

}

void Graphics_scene::slot_timer()
{
    auto elems = items();

    for (auto elem : elems){
        if (auto item{dynamic_cast<Snake *>(elem)};
                item){
            item->Moving();

            if (item->pos().x() < 0 or item->pos().y() < 0 or
                    item->pos().x() >= weight_ or item->pos().y() >= height_){

                start_stop_game(false);
                QMessageBox::information(nullptr,
                                         "Game Over",
                                         item->get_player() == Player::PLAYER_ONE ? "Синий игрок проиграл!" : "Красный игрок проиграл");
                emit exit_game();
            }
        }
    }

    auto collise = collidingItems(snake1);

    if (collise.size() != 0){
        if (auto item{dynamic_cast<Snake *>(collise.at(0))};
                item){
            start_stop_game(false);
            QMessageBox::information(nullptr, "Game Over", "Ничья");
            emit exit_game();
        }
        if (auto item{dynamic_cast<Eat *>(collise.at(0))};
                item){

            snake1->create_body();
            emit add_score(Player::PLAYER_ONE);
            removeItem(item);
        }
        if (auto item{dynamic_cast<Body *>(collise.at(0))};
                item){

            start_stop_game(false);
            QMessageBox::information(nullptr, "Game Over", "Синий игрок проиграл!");
            emit exit_game();
        }

    }

    collise = collidingItems(snake2);

    if (collise.size() != 0){
        if (auto item{dynamic_cast<Snake *>(collise.at(0))};
                item){
            start_stop_game(false);
//            QMessageBox::information(nullptr, "Game Over", "Красный игрок проиграл!");
            emit exit_game();
        }
        if (auto item{dynamic_cast<Eat *>(collise.at(0))};
                item){

            snake2->create_body();
            emit add_score(Player::PLAYER_TWO);
            removeItem(item);
        }
        if (auto item{dynamic_cast<Body *>(collise.at(0))};
                item){

            start_stop_game(false);
            QMessageBox::information(nullptr, "Game Over", "Красный игрок проиграл!");
            emit exit_game();
        }
    }

    collise = collidingItems(snake3);

    if (collise.size() != 0){
        if (auto item{dynamic_cast<Snake *>(collise.at(0))};
                item){
            start_stop_game(false);
//            QMessageBox::information(nullptr, "Game Over", "Зеленый игрок проиграл!");
            emit exit_game();
        }
        if (auto item{dynamic_cast<Eat *>(collise.at(0))};
                item){

            snake3->create_body();
            emit add_score(Player::PLAYER_THREE);
            removeItem(item);
        }
        if (auto item{dynamic_cast<Body *>(collise.at(0))};
                item){

            start_stop_game(false);
            QMessageBox::information(nullptr, "Game Over", "Зеленый игрок проиграл!");
            emit exit_game();
        }
    }

}

void Graphics_scene::slot_timer_eat()
{
    auto eat = new Eat();
    auto x = std::round((rand() % (weight_-25)) / 25) * 25;
    auto y = std::round((rand() % (height_ - 25)) / 25) * 25;
    eat->setPos(x, y);

//    array_eat.push_back(eat);
    addItem(eat);

    time_rand = std::rand() % 4;

    timer_eat->start(time_rand * 1000);
}
