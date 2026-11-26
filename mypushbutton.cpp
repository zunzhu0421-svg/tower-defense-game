#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent)
//    : QWidget{parent}
//{

//}
MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    normalImgPath=normalImg;
    pressImgPath=pressImg;
    QPixmap pix;
    bool ret =pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<"picture fail";
        return;
    }
    setFixedSize(pix.width(),pix.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setIcon(pix);
    setIconSize(QSize(pix.width(),pix.height()));
    show();
}
void MyPushButton::zoomup()
{
    QPropertyAnimation* animation1=new QPropertyAnimation(this,"geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}
void MyPushButton::zoomdown()
{
    QPropertyAnimation* animation1=new QPropertyAnimation(this,"geometry");
    animation1->setDuration(500);
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}
void MyPushButton::mousePressEvent(QMouseEvent* e)
{
   if(pressImgPath!="")
   {
       QPixmap pix;
       bool ret =pix.load(pressImgPath);
       if(!ret)
       {
           qDebug()<<"picture fail";
           return;
       }
       setFixedSize(pix.width(),pix.height());
       setStyleSheet("QPushButton{border:Opx;}");
       setIcon(pix);
       setIconSize(QSize(pix.width(),pix.height()));
   }
   return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent* e)
{
    if(pressImgPath!="")
    {
        QPixmap pix;
        bool ret =pix.load(normalImgPath);
        if(!ret)
        {
            qDebug()<<"picture fail";
            return;
        }
        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:Opx;}");
        setIcon(pix);
        setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
 }

