#include "remotepushbutton.h"
#include<QDebug>
#include<QMouseEvent>
RemotePushButton::RemotePushButton(QWidget* t)
{
    w=t;
    bool ret =RemoteBtnImg.load(":/Image/remote_cell.png");
    if(!ret)
    {
        qDebug()<<"picture fail";
        return;
    }
    ret =CircleImg.load(":/Image/circle.png");
    if(!ret)
    {
        qDebug()<<"picture fail";
        return;
    }
    Circle=new QLabel;
    Circle->hide();
    Circle->setParent(w);
    Circle->setFixedSize(CircleImg.width(),CircleImg.height());
    Circle->setStyleSheet("QPushButton{border:Opx;}");
    Circle->setPixmap(CircleImg);
    Circle->setBaseSize(QSize(CircleImg.width(),CircleImg.height()));
    Circle->setAttribute(Qt::WA_TransparentForMouseEvents);
    setFixedSize(RemoteBtnImg.width(),RemoteBtnImg.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setIcon(RemoteBtnImg);
    setIconSize(QSize(RemoteBtnImg.width(),RemoteBtnImg.height()));
    setAttribute(Qt::WA_TransparentForMouseEvents);
    show();
    choose_btns[0]=new ChooseButton(":/Image/tower1_btn.png");
    choose_btns[1]=new ChooseButton(":/Image/tower2_btn.png");
    choose_btns[2]=new ChooseButton(":/Image/tower3_btn.png");
    for(int i=0;i<3;i++)
    {
        choose_btns[i]->setParent(w);
        choose_btns[i]->hide();
    }
}
void RemotePushButton::MymousePressEvent(int x,int y)
{
    if(state)
    {
        if(isclicked)
        {
            isclicked=0;
            Circle->hide();
            for(int i=0;i<3;i++)
            choose_btns[i]->hide();
        }
        else
        {
            if(x>=this->x()&&x<=this->x()+this->width()
                    &&y>=this->y()&&y<=this->y()+this->height())
            {
                Circle->move(this->x()+1.0/2*this->width()-1.0/2*Circle->width(),this->y()+1.0/2*this->height()-1.0/2*Circle->height());
                Circle->show();
                Circle->raise();
                choose_btns[0]->move(Circle->x()+47,Circle->y()+2);
                choose_btns[1]->move(Circle->x()+85,Circle->y()+55);
                choose_btns[2]->move(Circle->x()+9,Circle->y()+55);
                for(int i=0;i<3;i++)
                {
                    choose_btns[i]->show();
                    choose_btns[i]->raise();
                }
                isclicked=1;
            }

        }
    }
}
