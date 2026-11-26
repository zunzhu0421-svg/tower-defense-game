#ifndef ENEMY_H
#define ENEMY_H
#include"map.h"
#include<QLabel>
class Soldiers;
enum enemy_type
{
    ground_enemy,
    fly_enemy,
    fly_enemy2
};
enum enemy_state
{
    left,
    right,
    up,
    down
};

class Enemy:public QLabel
{
protected:
    int hp=40;
    Map* e_map;
    QPixmap enemyleft1_Img;
    QPixmap enemyleft2_Img;
    QPixmap enemyright1_Img;
    QPixmap enemyright2_Img;
    QPixmap enemyattackleft_Img;
    QPixmap enemyattackright_Img;
    QPixmap enemyattackleft2_Img;
    QPixmap enemyattackright2_Img;
    int distance=0;
    int speed=4;
    int move_interval=2000;
    int isblocked=0;
    int attack_range;
    Soldiers* target_soldier=NULL;
    int attack=1;
    int die=0;
    int type=ground_enemy;
    int direction=left;
    int isImg1=1;
    int isattack=0;
    int arrive=0;
    int road_index;
    int isleft=1;
    int attackImg=0;
public:
    Enemy();
    int get_distance()const{return distance;};
    void add_distance(int add){distance+=add;};
    int get_speed()const{return speed;};
    int get_moveinterval()const{return move_interval;};
    void moveEnemy(int road_index,int d);
    bool isactive();
    void be_attacked(int attack);
    void be_blocked(){distance-=speed;};
    int get_isblocked()const{return isblocked;};
    void set_isblocked(){isblocked=1;};
    void choose_enemy(QVector<Soldiers*> sodier);
    double dis(int x,int y);
    void attack_soldier();
    int get_hp()const{return hp;};
    int get_die()const{return die;};
    void reset_isblocked(){isblocked=0;};
    int get_type()const{return type;};
    virtual void move_animation();
    int get_isattack(){return isattack;};
    bool isarrive();
    void set_roadindex(int t){road_index=t;};
    virtual void attack_animation();
    int get_attackrange(){return attack_range;};
};

#endif // ENEMY_H
