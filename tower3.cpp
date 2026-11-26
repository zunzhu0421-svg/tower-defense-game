#include "tower3.h"

Tower3::Tower3()
{
    bool ret =TowerImg.load(":/Image/tower3.png");
    if(!ret)
    {
        qDebug()<<"picture fail";
        return;
    }
    setFixedSize(TowerImg.width(),TowerImg.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setPixmap(TowerImg);
    setBaseSize(QSize(TowerImg.width(),TowerImg.height()));
    setAttribute(Qt::WA_TransparentForMouseEvents);
    t_map=new Map;
}
