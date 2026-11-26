#ifndef ENEMYFLY_H
#define ENEMYFLY_H
#include"enemy.h"
#include"tower.h"
#include"bullet.h"
class EnemyFly:public Enemy
{
protected:
    Tower* target_tower=NULL;
    QPixmap leftImg[4];
    QPixmap rightImg[4];
    int Imgcount=0;
    int isleft;
    QPixmap bulletImg;
    int bullet_flag=0;
    int bullet_interval=5;
public:
    EnemyFly();
    void chooseEnemy(QVector<Soldiers*> sodier,QVector<Tower*>);
    void move_animation();
    void attack_animation();
};

#endif // ENEMYFLY_H
