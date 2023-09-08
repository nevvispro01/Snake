#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <unistd.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    setCentralWidget(game);
//    game->start_game();

    ui->widget_2->setVisible(false);

    connect(ui->widget_2, &Game::go_to_main_menu, [this]{

        ui->widget->setVisible(true);
        ui->widget_2->setVisible(false);

//        ui->widget_2->stop_game();
//        game->start_game();
    });

    connect(ui->widget, &Main_menu::start_new_game, [this]{

        ui->widget->setVisible(false);
        ui->widget_2->setVisible(true);

        ui->widget_2->start_game();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
