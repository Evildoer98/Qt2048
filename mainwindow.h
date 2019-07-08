#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "gamelogic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    gamelogic game; //调用游戏算法类
    int totscore;   //定义分数
    void showbroad();   //显示并更新所有方块
    void keyPressEvent(QKeyEvent *event);   //按键事件及得分
    void changeColor(QLabel* label, int num);//设置每种基础数字色块对应的方块颜色
    void restart();     //重新开始
    ~MainWindow();

private slots:
    void on_restartButton_clicked();    //重新开始（点击事件）

    void on_quitButton_clicked();   //退出（点击事件）

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
