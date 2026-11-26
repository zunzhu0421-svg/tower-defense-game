#ifndef TOWER_H
#define TOWER_H
#include<QPainter>
#include"map.h"
#include<QLabel>
#include"enemy.h"
class Tower:public QLabel
{
protected:
    int cost=100;
    int level=1;
    int attack=1;
    int attackinterval=500;
    QPixmap TowerImg;
    Map* t_map;
    int isattack=0;
    int HP=10000;
    int putdown_success=0;
    Enemy* target_enemy;
    int attack_range=2;
    RemotePushButton* btn;
public:
    Tower();
    int get_attack()const{return attack;};
    int get_putdownsuccess()const{return putdown_success;};
    int get_HP()const{return HP;};
    void set_map(Map* map);
    bool attackjudge(int x,int y);
    bool isactive();
    void attack_enemy();
    void be_attacked(int attack);
    int get_cost()const{return cost;};
    virtual void choose_enemy(QVector<Enemy*> enemy);
    int get_attackrange(){return attack_range;};
    void set_btn(RemotePushButton* t){btn=t;};
signals:

};

#endif // TOWER_H
