#include "enemy2.h"
#include"bullet.h"
Enemy2::Enemy2()
{
    bool ret =enemyleft1_Img.load(":/Image/remoteenemyleft1.png");
    ret =enemyleft2_Img.load(":/Image/remoteenemyleft2.png");
    ret =enemyright2_Img.load(":/Image/remoteenemyright2.png");
    ret =enemyright1_Img.load(":/Image/remoteenemyright1.png");
    ret =enemyattackright_Img.load(":/Image/remoteenemyattackright.png");
    ret =enemyattackleft_Img.load(":/Image/remoteenemyattackleft.png");
    ret=enemyattackleft2_Img.load(":/Image/remoteenemyattackleft2.png");
    ret =enemyattackright2_Img.load(":/Image/remoteenemyattackright2.png");
    bulletImg.load(":/Image/remoteenemybullet.png");
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
    attack_range=3;
}
void Enemy2::attack_animation()
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
        if(bullet_flag==0)
        {
            Bullet* b=new Bullet(bulletImg);
        b->move(x(),y()+27);
        b->setParent(this->parentWidget());
        b->show();
        b->move_to_target(target_soldier);
        bullet_flag=1;
        }
        else
        {
            bullet_flag++;
            bullet_flag%=bullet_interval;
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
        if(bullet_flag==0)
        {
            Bullet* b=new Bullet(bulletImg);
        b->move(x()+60,y()+27);
        b->setParent(this->parentWidget());
        b->show();
        b->move_to_target(target_soldier);
        bullet_flag=1;
        }
        else
        {
            bullet_flag++;
            bullet_flag%=bullet_interval;
        }
    }

}

