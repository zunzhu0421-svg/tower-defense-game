#ifndef REMOTEPUSHBUTTON_H
#define REMOTEPUSHBUTTON_H
#include<QPushButton>
#include"choosebutton.h"
#include<QWidget>
#include<QLabel>
class RemotePushButton:public QPushButton
{
    QPixmap RemoteBtnImg;
    QPixmap CircleImg;
    QLabel* Circle;
    QWidget* w;
    int isclicked=0;
    int state=1;
public:
    RemotePushButton(QWidget* t);
    void MymousePressEvent(int x,int y);
    ChooseButton* choose_btns[3];
    void set_state(int t){state=t;};
};

#endif // REMOTEPUSHBUTTON_H
