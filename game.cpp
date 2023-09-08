#include "game.h"
#include "ui_game.h"

#include "graphics_scene.h"
#include "common.h"

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);


}

Game::~Game()
{
    delete ui;
}

void Game::start_game()
{
    ui->num_score->setText("0");
    ui->num_score_2->setText("0");
    ui->num_score_3->setText("0");

    auto scene = new Graphics_scene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0,0,weight_, height_);

    connect(scene, &Graphics_scene::add_score, this, &Game::add_score);
//    connect(scene, &Graphics_scene::add_score_second, [this]{

//        ui->num_score_2->setText(QString::number(ui->num_score_2->text().toInt() + 1));
//    });

    connect(scene, &Graphics_scene::exit_game, [this]{

        emit go_to_main_menu();
    });

    connect(ui->pushButton, &QPushButton::clicked, [this, scene]{

        if (ui->pushButton->text() == "Пауза"){
            ui->pushButton->setText("Старт");
            scene->start_stop_game(false);
        }else{
            ui->pushButton->setText("Пауза");
            scene->start_stop_game(true);
        }
    });

    static_cast<Graphics_scene *>(ui->graphicsView->scene())->start_stop_game(true);
}

void Game::add_score(Player player_)
{
    switch (player_) {
    case Player::PLAYER_ONE:
        ui->num_score->setText(QString::number(ui->num_score->text().toInt() + 1));
        break;
    case Player::PLAYER_TWO:
        ui->num_score_2->setText(QString::number(ui->num_score_2->text().toInt() + 1));
        break;
    case Player::PLAYER_THREE:
        ui->num_score_3->setText(QString::number(ui->num_score_3->text().toInt() + 1));
        break;

    }
}
