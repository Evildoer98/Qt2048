#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <ctime>
#include <windows.h>
#include <QLabel>
#include <QPalette>
#include <QColor>
#include <QMessageBox>
#include "bg2048.h"

using namespace std;

bg2048 *p;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    totscore = 0;
    ui->setupUi(this);
    setFixedSize(862,800);


    p = new bg2048(this);
    p->show();
}

//显示并更新所有方块
void MainWindow::showbroad()
{
    //第一行第一列，ui的数据显示
    if(game.pix[0][0])  ui->label1->setText(QString::number(game.pix[0][0]));
    else ui->label1->setText(" ");  //否则为方块为空
    changeColor(ui->label1, game.pix[0][0]);
    //第一行第二列
    if(game.pix[0][1])  ui->label2->setText(QString::number(game.pix[0][1]));
    else ui->label2->setText(" ");
    changeColor(ui->label2, game.pix[0][1]);
    //第一行第三列
    if(game.pix[0][2])  ui->label3->setText(QString::number(game.pix[0][2]));
    else ui->label3->setText(" ");
    changeColor(ui->label3, game.pix[0][2]);
    //第一行第四列
    if(game.pix[0][3])  ui->label4->setText(QString::number(game.pix[0][3]));
    else ui->label4->setText(" ");
    changeColor(ui->label4, game.pix[0][3]);

    //以下同理
    //第二行
    if(game.pix[1][0])  ui->label5->setText(QString::number(game.pix[1][0]));
    else ui->label5->setText(" ");
    changeColor(ui->label5, game.pix[1][0]);

    if(game.pix[1][1])  ui->label6->setText(QString::number(game.pix[1][1]));
    else ui->label6->setText(" ");
    changeColor(ui->label6, game.pix[1][1]);

    if(game.pix[1][2])  ui->label7->setText(QString::number(game.pix[1][2]));
    else ui->label7->setText(" ");
    changeColor(ui->label7, game.pix[1][2]);

    if(game.pix[1][3])  ui->label8->setText(QString::number(game.pix[1][3]));
    else ui->label8->setText(" ");
    changeColor(ui->label8, game.pix[1][3]);

    //第三行
    if(game.pix[2][0])  ui->label9->setText(QString::number(game.pix[2][0]));
    else ui->label9->setText(" ");
    changeColor(ui->label9, game.pix[2][0]);

    if(game.pix[2][1])  ui->label10->setText(QString::number(game.pix[2][1]));
    else ui->label10->setText(" ");
    changeColor(ui->label10, game.pix[2][1]);

    if(game.pix[2][2])  ui->label11->setText(QString::number(game.pix[2][2]));
    else ui->label11->setText(" ");
    changeColor(ui->label11, game.pix[2][2]);

    if(game.pix[2][3])  ui->label12->setText(QString::number(game.pix[2][3]));
    else ui->label12->setText(" ");
    changeColor(ui->label12, game.pix[2][3]);

    //第四行
    if(game.pix[3][0])  ui->label13->setText(QString::number(game.pix[3][0]));
    else ui->label13->setText(" ");
    changeColor(ui->label13, game.pix[3][0]);

    if(game.pix[3][1])  ui->label14->setText(QString::number(game.pix[3][1]));
    else ui->label14->setText(" ");
    changeColor(ui->label14, game.pix[3][1]);

    if(game.pix[3][2])  ui->label15->setText(QString::number(game.pix[3][2]));
    else ui->label15->setText(" ");
    changeColor(ui->label15, game.pix[3][2]);

    if(game.pix[3][3])  ui->label16->setText(QString::number(game.pix[3][3]));
    else ui->label16->setText(" ");
    changeColor(ui->label16, game.pix[3][3]);

}

//改变每种数字对应的方块颜色
void MainWindow::changeColor(QLabel* label, int num)
{
    QPalette palette;
    switch (num)
    {
    case 2:
        palette.setColor(QPalette::Background,QColor(135,206,250));
        break;

    case 4:
        palette.setColor(QPalette::Background,QColor(255,160,122));
        break;

    case 8:
        palette.setColor(QPalette::Background,QColor(255,222,173));
        break;

    case 16:
        palette.setColor(QPalette::Background,QColor(245,150,100));
        break;

    case 32:
        palette.setColor(QPalette::Background,QColor(245,125,95));
        break;

    case 64:
        palette.setColor(QPalette::Background,QColor(245,95,60));
        break;

    case 128:
        palette.setColor(QPalette::Background,QColor(237,207,114));
        break;

    case 256:
        palette.setColor(QPalette::Background,QColor(237,204,97));
        break;

    case 512:
        palette.setColor(QPalette::Background,QColor(237,204,97));
        break;

    case 1024:
        palette.setColor(QPalette::Background,QColor(178,34,34));
        break;

    case 2048:
        palette.setColor(QPalette::Background,QColor(255,0,0));
        break;

    default:
        palette.setColor(QPalette::Background,QColor(238,228,218));
        break;
    }

    label->setAutoFillBackground(true);
    label->setPalette(palette);
}

//按键事件及得分
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int score = 0;  //初始化得分
    showbroad();    //显示并更新所有方块
    switch (event->key())
    {
    case Qt::Key_Left:
        score = game.Process(LEFT);
        break;

    case Qt::Key_Up:
        score = game.Process(UP);
        break;

    case Qt::Key_Right:
        score = game.Process(RIGHT);
        break;

    case Qt::Key_Down:
        score = game.Process(DOWN);
        break;

    default:
        return;
        break;
    }
    totscore += score;  //计算得分
    ui->score2->setText(QString::number(totscore));
    showbroad();    //计分后，显示并更新所有方块

    int Gamstate = game.Judge();
    srand((unsigned int)time(0));   //随机函数
     //判定游戏的结束，并且提示游戏结束
    if (Gamstate == GAME_CONTINUE)
    {
        if(game.CreatNumber()==0)
        {
            cout << "Sorry  " << "You lose the chance!" << endl;
            QMessageBox::information(NULL, "2048", "你赢啦！", QMessageBox::Yes , QMessageBox::Yes);
            //return GAME_OVER;
        }
        else showbroad();
    }
    else if(Gamstate == GAME_WIN)
    {
        cout << "Congratulation  " << "You Win！" << endl;
        //return GAME_WIN;
    }
    else
    {
        cout << "Sorry  " << "You lose the game!" << endl;
        QMessageBox::information(NULL, "2048", "游戏结束", QMessageBox::Yes , QMessageBox::Yes);
       // return GAME_OVER;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

//点击事件（重新开始）
void MainWindow::on_restartButton_clicked()
{
    QMessageBox message(QMessageBox::NoIcon, "2048", "Do you need to start ？", QMessageBox::Yes | QMessageBox::No, NULL);

   if(message.exec() == QMessageBox::Yes)
   {
         restart();
   }

//    QMessageBox::information(NULL, "2048", "游戏结束", QMessageBox::Yes , QMessageBox::No);
}


//刷新游戏界面，分数归零
void MainWindow::restart()
{
    //初始化所有方块
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            game.pix[i][j] = 0;

    //生成3个随机基础数2或者4
    game.CreatNumber();
    game.CreatNumber();
    game.CreatNumber();
    //显示并且重新更新所有方块
    showbroad();
    //将得分置零
    totscore = 0;
    //提醒是否需要再次开始，选择yes则重新开始，NO则取消
    ui->score2->setText(QString::number(totscore));
}

//点击事件（退出游戏）
void MainWindow::on_quitButton_clicked()
{
    QMessageBox message(QMessageBox::NoIcon, "2048", "Do you need to quit ？", QMessageBox::Yes | QMessageBox::No, NULL);

   if(message.exec() == QMessageBox::Yes)
   {
         close();
   }
}
