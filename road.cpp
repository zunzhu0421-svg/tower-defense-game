#include "road.h"
#include"enemy.h"
#include<QDebug>
Road::Road()
{

}
void Road::set_road(QVector<QVector<int>> r)
{
    for(int i=0;i<r.size();i++)
        for(int j=0;j<2;j++)
        {
            road[i][j]=r[i][j];
        }
    r_len=r.size();
}
int Road::direction(const int i)const
{
    if(road[i+1][0]==road[i][0]+1)
        return right;
    if(road[i+1][0]==road[i][0]-1)
        return left;
    if(road[i+1][1]==road[i][1]+1)
        return down;
    if(road[i+1][1]==road[i][1]-1)
        return up;
}
int Road::transtoxy(int d,int& _x,int&_y)const
{
    int width=map->get_width();
    int x=road[0][0]*width;
    int y=road[0][1]*width;
    int dir,t;
    for(int i=0;i<r_len-1&&d;i++)
    {
        dir=direction(i);
        if(d>width)
        {
            t=width;
            d-=width;
        }
        else
        {
            t=d;
            d=0;
        }
        switch(dir)
        {
        case right:
            x+=t;
            break;
        case left:
            x-=t;
            break;
        case down:
            y+=t;
            break;
        case up:
            y-=t;
            break;
        }
    }
    _x=x;
    _y=y;
    return dir;
}
