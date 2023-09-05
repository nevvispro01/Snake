#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    srand(time(0));

    w.showFullScreen();
    return a.exec();
}
