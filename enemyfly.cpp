#include "enemyfly.h"
#include"soldiers.h"
EnemyFly::EnemyFly()
{

    bool ret =rightImg[0].load(":/Image/enemyfly2right1.png");
    ret =rightImg[1].load(":/Image/enemyfly2right2.png");
    ret =rightImg[2].load(":/Image/enemyfly2right3.png");
    ret =rightImg[3].load(":/Image/enemyfly2right4.png");
    ret =leftImg[0].load(":/Image/enemyfly2left1.png");
    ret =leftImg[1].load(":/Image/enemyfly2left2.png");
    ret =leftImg[2].load(":/Image/enemyfly2left3.png");
    ret =leftImg[3].load(":/Image/enemyfly2left4.png");
    for(int i=0;i<4;i++)
    {
        rightImg[i]=rightImg[i].scaled(50,50*rightImg[i].height()/rightImg[i].width(),Qt::KeepAspectRatio);
        leftImg[i]=leftImg[i].scaled(50,50*leftImg[i].height()/leftImg[i].width(),Qt::KeepAspectRatio);
    }
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
    type=fly_enemy;
    hp=40;
    attack_range=2;
    bulletImg.load(":/Image/enemyflybullet.png");
}
void EnemyFly::move_animation()
{
    if(direction==left)
    {
        isleft=1;
    }
    else if(direction==right)
    {
        isleft=0;
    }
    if(isleft)
    {
        setPixmap(leftImg[Imgcount]);
        resize(QSize(leftImg[Imgcount].width(),leftImg[Imgcount].height()));
    }
    else
    {
        setPixmap(rightImg[Imgcount]);
        resize(QSize(rightImg[Imgcount].width(),rightImg[Imgcount].height()));
    }
    Imgcount++;
    Imgcount%=4;
}
void EnemyFly::chooseEnemy(QVector<Soldiers*> soldier,QVector<Tower*> tower)
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
        {
            attack_soldier();
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
        }

    }
}
void EnemyFly::attack_animation()
{
    QLabel* t;
    if(target_soldier)
    {
        t=target_soldier;
    }
    else
    {
        t=target_tower;
    }


    {
        if(bullet_flag==0)
        {
            Bullet* b=new Bullet(bulletImg);
            if(isleft)
                b->move(x(),y()+27);
            else
                b->move(x()+60,y()+27);
            b->setParent(this->parentWidget());
            b->show();
            b->move_to_target(t);
            bullet_flag=1;
        }
        else
        {
            bullet_flag++;
            bullet_flag%=bullet_interval;
        }
    }


}
