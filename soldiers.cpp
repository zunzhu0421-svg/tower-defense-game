#include "soldiers.h"
int extern coins;
Soldiers::Soldiers()
{
    s_btn=new SoldierButton(":/Image/soldier1_btn.jpg");
    bool ret =soldierImg.load(":/Image/soldier1.png");
    soldierattackright_Img.load(":/Image/soldier1attackright1.png");
    soldierattackright2_Img.load(":/Image/soldier1attackright2.png");
    soldierattackleft_Img.load(":/Image/soldier1attackleft1.png");
    soldierattackleft2_Img.load(":/Image/soldier1attackleft2.png");
    if(!ret)
    {
        qDebug()<<"picture fail";
        return;
    }
    setFixedSize(soldierImg.width(),soldierImg.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setPixmap(soldierImg);
    setBaseSize(QSize(soldierImg.width(),soldierImg.height()));
    m=new Map;
}
void Soldiers::Picturemove(QMouseEvent* event)
{
    if(type==1)
    this->move(event->x()+895,event->y()-20);
    if(type==2)
    this->move(event->x()+895,event->y()+130);
    this->show();
    this->raise();
    this->setAttribute(Qt::WA_TransparentForMouseEvents);
}
void Soldiers::mouseReleaseEvent(QMouseEvent* e)
{
    //qDebug()<<coins;
    if(check_pos(e)&&coins>=cost)
    {
        show();
        coins-=cost;
        putdown_success=1;
        //qDebug()<<putdown_success;
    }
    else
        this->close();
}
bool Soldiers::check_pos(QMouseEvent* e)
{
    int w=m->get_width();
    int _x,_y;
    if(type==1)
    {
        _x=(e->x()+940)/w;
        _y=e->y()/w;
    }
    if(type==2)
    {
        _x=(e->x()+940)/w;
        _y=(e->y()+150)/w;
    }
    if(_x>=0&&_x<m->get_maplen()/w&&_y>=0&&_y<m->get_height()/w&&m->get_ground(_x,_y)==close_cell)
    {
        sx=_x;
        sy=_y;
        move(_x*w+1.0/2*m->get_width()-1.0/2*width(),_y*w+1.0/2*m->get_width()-1.0/2*height());
        return true;
    }
    else
    {
        return false;
    }
}
bool Soldiers::attackjudge(int x,int y)
{
    int w=m->get_width();
    if(blockedenemy_num==blocking_number)
        return false;
    if(dis(x,y)<=(double)w&&dis(x,y)>=(double)w/2)
    {
        return true;
    }
    return false;
}
double Soldiers::dis(int x,int y)
{
    double d=sqrt((x-this->x())*(x-this->x())+(y-this->y())*(y-this->y()));
    return d;
}
void Soldiers::attack_enemy()
{
    if(blocked_enemy.size()>0)
    {
        if(blockedenemy_num>0)
        {
            int index=0;
            for(auto ep : blocked_enemy)
            {
                if(!ep->isactive())
                {
                    blocked_enemy.remove(index);
                    blockedenemy_num--;
                }
                index++;
            }
            if(blocked_enemy.size()>0)
            {
                blocked_enemy[0]->be_attacked(attack);
                    if(x()<blocked_enemy[0]->x())
                    {
                        if(attackImg)
                    {
                        setPixmap(soldierattackright_Img);
                        raise();
                        attackImg=0;
                    }
                    else
                    {
                        setPixmap(soldierattackright2_Img);
                        raise();
                        attackImg=1;
                    }
                    }
                    else
                    {
                        if(attackImg)
                    {
                        setPixmap(soldierattackleft_Img);
                        move(sx*m->get_width()+1.0/2*m->get_width()-1.0/2*width(),sy*m->get_width()+1.0/2*m->get_width()-1.0/2*height());
                        raise();
                        attackImg=0;
                    }
                    else
                    {
                        setPixmap(soldierattackleft2_Img);
                        move(sx*m->get_width()+1.0/2*m->get_width()-1.0/2*width(),sy*m->get_width()+1.0/2*m->get_width()-1.0/2*height());
                        raise();
                        attackImg=1;
                    }
                    }
            }
            else
            {
                setPixmap(soldierImg);
                move(sx*m->get_width(),sy*m->get_width());
            }
            for(auto ep : blocked_enemy)
            {
                ep->be_blocked();

            }
        }
    }
    else
        blockedenemy_num=0;
}
void Soldiers::addto_enemyVector(Enemy *enemy)
{
    blocked_enemy.append(enemy);
    blockedenemy_num++;
    enemy->set_isblocked();
}
void Soldiers::be_attacked(int attack)
{
    HP-=attack;
}
bool Soldiers::isactive()
{
    if(HP>0)
        return true;
    for(auto ep : blocked_enemy)
    {
        ep->reset_isblocked();
    }
    blocked_enemy.clear();
    blockedenemy_num=0;
    this->hide();
    return false;
}
