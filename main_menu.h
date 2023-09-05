#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QWidget>

namespace Ui {
class Main_menu;
}

class Main_menu : public QWidget
{
    Q_OBJECT

public:
    explicit Main_menu(QWidget *parent = nullptr);
    ~Main_menu();

signals:

    void start_new_game();

private:
    Ui::Main_menu *ui;
};

#endif // MAIN_MENU_H
