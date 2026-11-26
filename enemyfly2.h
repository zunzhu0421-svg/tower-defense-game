#ifndef ENEMYFLY2_H
#define ENEMYFLY2_H
#include"enemyfly.h"
class EnemyFly2:public EnemyFly
{

public:
    void chooseEnemy(QVector<Soldiers*> sodier,QVector<Tower*>);
    EnemyFly2();
};

#endif // ENEMYFLY2_H
