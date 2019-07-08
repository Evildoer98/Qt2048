#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <random>   //产生随机数
#include <iostream> //输入输出流
#include <ctime>    //时间
#include <vector>   //能够存放任意类型的动态数组，能够增加和压缩数据
#include <windows.h> //计算机基本头文件，在该游戏中主要是提供延迟函数头文件
#include <QKeyEvent> //键盘事件

//游戏的行和列
#define ROW 4
#define COL 4

//游戏所处的状态
#define GAME_OVER 1
#define GAME_WIN 2
#define GAME_CONTINUE 3

//上下左右
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

class gamelogic
{
public:
    int pix[4][4];  //定义所有方块

    gamelogic();    //初始化
    bool CreatNumber(); //产生随机数字
    int Process(int dir);   //识别按键
    int remove(int dir);    //处理键盘事件，移动、合并、计分
    int Judge();    //判断游戏状态
//    int Input();

};

#endif // GAMELOGIC_H
