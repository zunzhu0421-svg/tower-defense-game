#ifndef TOWER1_H
#define TOWER1_H
#include"tower.h"

class Tower2:public Tower
{
public:
    Tower2();
    void choose_enemy(QVector<Enemy*> enemy);
};

#endif // TOWER1_H
