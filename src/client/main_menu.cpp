#include "main_menu.h"
#include "ui_main_menu.h"

Main_menu::Main_menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Main_menu)
{
    ui->setupUi(this);

    connect(ui->new_game, &QPushButton::clicked, [this]{

        emit start_new_game();
    });
}

Main_menu::~Main_menu()
{
    delete ui;
}
