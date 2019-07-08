#ifndef BG2048_H
#define BG2048_H

#include <QMainWindow>

namespace Ui {
class bg2048;
}

class bg2048 : public QMainWindow
{
    Q_OBJECT

public:
    explicit bg2048(QWidget *parent = 0);
    ~bg2048();

private slots:
    void on_bg_clicked();   //点击事件“PLAY”

private:
    Ui::bg2048 *ui;
};

#endif // BG2048_H
