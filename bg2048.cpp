#include "bg2048.h"
#include "ui_bg2048.h"
#include <QMessageBox>
bg2048::bg2048(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bg2048)
{
    ui->setupUi(this);
    setFixedSize(862,800);
}

bg2048::~bg2048()
{
    delete ui;
}

void bg2048::on_bg_clicked()
{
    //构造QMessageBox函数，通过判断进行进入游戏界面
    QMessageBox message(QMessageBox::NoIcon, "2048", "Do you need to start ？", QMessageBox::Yes | QMessageBox::No, NULL);
    //玩家选择“YES”则进入游戏，“NO”则不做任何操作
   if(message.exec() == QMessageBox::Yes)
   {
         close();
   }
}
