#ifndef MAP_H
#define MAP_H
#include<QPainter>
#include"remotepushbutton.h"
enum cell_type
{
    remote_cell=0,
    stone_cell,
    close_cell,
    start_cell,
    end_cell
};

class Road;
class Map
{
private:
    int m_len=1050;
    int height=630;
    int ground[13][9]={0};
    int width=70;
    QPixmap StoneImg;
    QPixmap RemoteImg;
    QPixmap CloseImg;
    QPixmap StartImg;
    QPixmap EndImg;
    int r_num;
    int remote_num;
public:
    RemotePushButton** AllRemoteButtons;
    Road* allroad;
    Map();
    Map(QString t);
    void putin_map();
    int get_maplen()const{return m_len;};
    int get_width()const;
    int get_height()const{return height;};
    void paint(QWidget* w);
    int get_ground(int x,int y)const{return ground[x][y];};
    int get_roadnum()const{return r_num;};
    int get_remotennum()const{return remote_num;};
};

#endif // MAP_H
