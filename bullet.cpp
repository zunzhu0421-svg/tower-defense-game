#include "bullet.h"

Bullet::Bullet(QPixmap b)
{
   bulletImg=b;
   setPixmap(b);
   setFixedSize(bulletImg.width(),bulletImg.height());
   setStyleSheet("QPushButton{border:Opx;}");
   setBaseSize(QSize(bulletImg.width(),bulletImg.height()));
   hide();
}
void Bullet::move_to_target(QLabel* t)
{
    b_timer=new QTimer;
    b_timer->start(100);
    connect(b_timer,&QTimer::timeout,[=](){
            int _x=x()-(t->x()+1.0/2*t->width()+20);
            int _y=y()-(t->y()+1.0/2*t->height());
           double d=sqrt(_x*_x+_y*_y);
           if(d<=10)
               state=0;
           if(state)
           {
               qDebug()<<d;
           qDebug()<<_x<<_y;
           qDebug()<<x()-10/d*_x<<y()-10/d*_y;
           move(x()-10/d*_x,y()-10/d*_y);
           }
           else
           {
               hide();
           }
    });
}
