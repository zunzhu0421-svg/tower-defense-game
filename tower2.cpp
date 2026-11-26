#include "tower2.h"

Tower2::Tower2()
{
    bool ret =TowerImg.load(":/Image/tower2.png");
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
void Tower2::choose_enemy(QVector<Enemy*> enemy)
{
    target_enemy=NULL;
    if(enemy.size()>0)
    {
        double t;
        int w=t_map->get_width();
        double d=attack_range*w;
        for(auto ep:enemy)
        {
            if(ep->isactive()&&ep->get_type()==ground_enemy)
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
