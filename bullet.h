#ifndef BULLET_H
#define BULLET_H
#include"QLabel"
#include<QTimer>
class Bullet:public QLabel
{
public:
    int state=1;
    QPixmap bulletImg;
    QTimer* b_timer;
    Bullet(QPixmap t);
    void move_to_target(QLabel*);
};

#endif // BULLET_H
