#include "tower.h"
#include<QDebug>
Tower::Tower()
{
    bool ret =TowerImg.load(":/Image/tower1.png");
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
void Tower:: choose_enemy(QVector<Enemy*> enemy)
{
    target_enemy=NULL;
    if(enemy.size()>0)
    {
        double t;
        int w=t_map->get_width();
        double d=attack_range*w;
        for(auto ep:enemy)
        {
            if(ep->isactive())
            {
                t=ep->dis(x(),y());
                if(t<=d)
                {
                    d=t;
                    target_enemy=ep;
                }
            }
        }
        if(target_enemy)
            attack_enemy();
    }
}
void Tower::attack_enemy()
{
    target_enemy->be_attacked(attack);
}
void Tower::be_attacked(int attack)
{
    HP-=attack;
}
bool Tower::isactive()
{
//    qDebug()<<HP;
    if(HP>=0)
        return true;
    hide();
    btn->set_state(1);
    return false;
}

