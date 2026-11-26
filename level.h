#ifndef LEVEL_1_H
#define LEVEL_1_H
#include <QWidget>
#include"soldiers.h"
#include"tower.h"
#include"map.h"
#include"enemy.h"
#include<QVector>
class Level : public QWidget
{
    Q_OBJECT
private:
    QVector<Enemy*>enemyVector;
    QVector<Soldiers*>soldierVector;
    QVector<Tower*>towerVector;
    QTimer *timer0;
    QTimer *timer1;
    QTimer *timer2;
    int goldcoins=500;
    Soldiers* s1,*s2;
    Map* map;
    QLabel* moneylabel;
    QLabel* moneynum;
    QLabel* lifelabel;
    QLabel* lifenum;
    QLabel *winLabel;
    QLabel *failLabel;
    int life=5;
    int over=0;
    int win=0;
    int enemy_num=100;
public:
    //explicit level_1(QWidget *parent = nullptr);
    Level();
    void paintEvent(QPaintEvent *);
    void game_start();
    void enemy_action(int type1num=0,int type2num=0,int type3num=0,int type4num=0);
    void Sleep(int msec);
    void moveArmy();
    void mousePressEvent(QMouseEvent* event);
signals:
    void clicks1();
    void tonext();
};

#endif // LEVEL_1_H
