#include "enemy.h"
#include"road.h"
#include<QTimer>
#include"soldiers.h"
Enemy::Enemy()
{
    bool ret =enemyleft1_Img.load(":/Image/enemyleft1.png");
    ret =enemyleft2_Img.load(":/Image/enemyleft2.png");
    ret =enemyright2_Img.load(":/Image/enemyright2.png");
    ret =enemyright1_Img.load(":/Image/enemyright1.png");
    ret =enemyattackright_Img.load(":/Image/enemyrightattack.png");
    ret =enemyattackleft_Img.load(":/Image/enemyleftattack.png");
    ret=enemyattackleft2_Img.load(":/Image/enemyleftattack2.png");
    ret =enemyattackright2_Img.load(":/Image/enemyrightattack2.png");
    if(!ret)
    {
        qDebug()<<"picture fail";
        return;
    }
    setFixedSize(enemyleft1_Img.width(),enemyleft1_Img.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setPixmap(enemyleft1_Img);
    setBaseSize(QSize(enemyleft1_Img.width(),enemyleft1_Img.height()));
    e_map=new Map;
    attack_range=1;
}
void Enemy::moveEnemy(int road_index,int d)
{
    int _x,_y,t;
    t=e_map->allroad[road_index].transtoxy(d,_x,_y);
    direction=t;
    move(_x+1.0/2*e_map->get_width()-1.0/2*width(),_y+1.0/2*e_map->get_width()-1.0/2*height());
}
void Enemy::be_attacked(int attack)
{
    isattack=1;
    hp-=attack;
}
void Enemy::choose_enemy(QVector<Soldiers*> soldier)
{
    if(isactive())
    {
        target_soldier=NULL;
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
            attack_soldier();

    }
    }
}
double Enemy::dis(int x,int y)
{
    double d=sqrt((x-this->x())*(x-this->x())+(y-this->y())*(y-this->y()));
    return d;
}
void Enemy::attack_soldier()
{
    if(target_soldier->isactive())
    {
        target_soldier->be_attacked(attack);
        attack_animation();
    }
}
void Enemy::attack_animation()
{
    if(x()>target_soldier->x())
    {
        if(attackImg)
        {
            setPixmap(enemyattackleft_Img);
            attackImg=0;
        }
        else
        {
            setPixmap(enemyattackleft2_Img);
            attackImg=1;
        }
    }
    else
    {
        if(attackImg)
        {
            setPixmap(enemyattackright_Img);
            attackImg=0;
        }
        else
        {
            setPixmap(enemyattackright2_Img);
            attackImg=1;
        }
    }
}
bool Enemy::isactive()
{
    if(!die&&hp<=0)
    {
        die=1;
        lower();
        hide();
    }
    if(hp>0)
        return true;
    return false;
}
void Enemy::move_animation()
{
    if(direction==left)
    {
        isleft=1;
    }
    else if(direction==right)
    {
        isleft=0;
    }
    switch(isleft)
    {
    case 1:
        if(isImg1)
        {
            setPixmap(enemyleft2_Img);
            resize(QSize(enemyleft2_Img.width(),enemyleft2_Img.height()));
            isImg1=0;
        }
        else
        {
            setPixmap(enemyleft1_Img);
            resize(QSize(enemyleft1_Img.width(),enemyleft1_Img.height()));
            isImg1=1;
        }
        break;
    case 0:
        if(isImg1)
        {
            setPixmap(enemyright2_Img);
            resize(QSize(enemyright2_Img.width(),enemyright2_Img.height()));
            isImg1=0;
        }
        else
        {
            setPixmap(enemyright1_Img);
            resize(QSize(enemyright1_Img.width(),enemyright1_Img.height()));
            isImg1=1;
        }
        break;
    }
}
bool Enemy::isarrive()
{
    if(!arrive)
    {
        int l=e_map->allroad[road_index].get_roadlen();
        int _x=e_map->allroad[road_index].get_road(l-1,0);
        int _y=e_map->allroad[road_index].get_road(l-1,1);
        int w=e_map->get_width();
        if(x()<=_x*w+5&&x()>=_x*w-5&&y()>=w*_y-5&&y()<=w*_y+5)
        {
            qDebug()<<"???????";
            arrive=1;
            die=1;
            return true;
        }
    }
    return false;
}
