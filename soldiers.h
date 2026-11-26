#ifndef SOLDIERS_H
#define SOLDIERS_H
#include<QImage>
#include<QPushButton>
#include<QLabel>
#include<QMouseEvent>
#include"soldierbutton.h"
#include"map.h"
#include"enemy.h"
class Soldiers:public QLabel
{
protected:
    int cost=100;
    int attack=2;
    int attackinterval=500;//射击时间间隔
    int blocking_number=1;
    QPixmap soldierImg;
    QPixmap soldierBtnImg;
    QPixmap soldierattackleft_Img;
    QPixmap soldierattackright_Img;
    QPixmap soldierattackleft2_Img;
    QPixmap soldierattackright2_Img;
    Map* m;
    int isattack=0;
    int blockedenemy_num=0;
    QVector<Enemy*>blocked_enemy;
    int HP=150;
    SoldierButton* s_btn;
     int putdown_success=0;
     int type=1;
     int attackImg=0;
     int sx;
     int sy;
public:
    int get_attack()const{return attack;};
    int get_putdownsuccess()const{return putdown_success;};
    int get_HP()const{return HP;};
    SoldierButton* get_SoldierButton()const{return s_btn;};
    Soldiers();
    void Picturemove(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* e);
    bool check_pos(QMouseEvent* e);
    void set_map(Map* map);
    bool attackjudge(int x,int y);
    bool isactive();
    double dis(int x,int y);
    void attack_enemy();
    void addto_enemyVector(Enemy* enemy);
    void be_attacked(int attack);
signals:

};

#endif // SOLDIERS_H
