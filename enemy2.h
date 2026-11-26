#ifndef ENEMY2_H
#define ENEMY2_H
#include"enemy.h"
#include"soldiers.h"
class Enemy2:public Enemy
{
    QPixmap bulletImg;
    int bullet_flag=0;
    int bullet_interval=5;
public:
    Enemy2();
    void attack_animation();
};

#endif // ENEMY2_H
