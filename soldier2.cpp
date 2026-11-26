#include "soldier2.h"

Soldier2::Soldier2()
{
    attack=0;
    blocking_number=3;
    HP=1000;
    s_btn=new SoldierButton(":/Image/soldier2_btn.png");
    bool ret =soldierImg.load(":/Image/soldier2.png");
    if(!ret)
    {
        qDebug()<<"picture fail";
        return;
    }
    setFixedSize(soldierImg.width(),soldierImg.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setPixmap(soldierImg);
    setBaseSize(QSize(soldierImg.width(),soldierImg.height()));
    m=new Map;
    type=2;
}
