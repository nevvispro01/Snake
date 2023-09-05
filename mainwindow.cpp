#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <unistd.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(game);
    game->start_game();

    connect(game, &Game::go_to_main_menu, [this]{
//        setCentralWidget(main_menu);
    });

    connect(main_menu, &Main_menu::start_new_game, [this]{

        setCentralWidget(game);

        game->start_game();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
