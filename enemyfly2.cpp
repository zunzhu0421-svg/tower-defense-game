#include "enemyfly2.h"
#include"soldiers.h"
EnemyFly2::EnemyFly2()
{

    bool ret =leftImg[0].load(":/Image/enemyflyleft1.png");
    ret =leftImg[1].load(":/Image/enemyflyleft2.png");
    ret =leftImg[2].load(":/Image/enemyflyleft3.png");
    ret =leftImg[3].load(":/Image/enemyflyleft4.png");
    ret =rightImg[0].load(":/Image/enemyflyright1.png");
    ret =rightImg[1].load(":/Image/enemyflyright2.png");
    ret =rightImg[2].load(":/Image/enemyflyright3.png");
    ret =rightImg[3].load(":/Image/enemyflyright4.png");
    if(!ret)
    {
        qDebug()<<"picture fail";
        return;
    }
    setFixedSize(enemyleft1_Img.width(),enemyleft1_Img.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setPixmap(enemyleft1_Img);
    setBaseSize(QSize(enemyleft1_Img.width(),enemyleft1_Img.height()));
    //picture
    e_map=new Map;
    //map
    type=fly_enemy2;
    hp=10;
}
void EnemyFly2::chooseEnemy(QVector<Soldiers*> soldier,QVector<Tower*> tower)
{
    isattack=0;
    target_soldier=NULL;
    if(isactive())
    {
        if(soldier.size()>0)
    {
        double t;
        int w=e_map->get_width();
        double d=attack_range*w;
        for(auto sp:soldier)
        {
            if(sp->isactive())
            {
                t=dis(sp->x(),sp->y());
                if(t<=d)
                {
                    d=t;
                    target_soldier=sp;
                }
            }
        }
        if(target_soldier)
        {
            attack_soldier();
            isattack=1;
            return;
        }

    }
    target_tower=NULL;
    if(tower.size()>0)
    {
        double t;
        int w=e_map->get_width();
        double d=attack_range*w;
        for(auto tp:tower)
        {
            if(tp->isactive())
            {
                t=dis(tp->x(),tp->y());
                if(t<=d)
                {
                    d=t;
                    target_tower=tp;
                }
            }
        }
        if(target_tower)
        {
            target_tower->be_attacked(attack);
            isattack=1;
            attack_animation();
        }

    }
    }
}

