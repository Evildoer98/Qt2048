#include "mainwindow.h"
#include <QApplication>
#include <QKeyEvent>
#include "ui_mainwindow.h"
#include <ctime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.showbroad();
    srand((unsigned int)time(0));   //随机发生器
    w.game.CreatNumber();
    w.game.CreatNumber();
    w.game.CreatNumber();
    Sleep(100); //延迟100毫秒
    w.showbroad();

    //w.startgame();


    return a.exec();
}
