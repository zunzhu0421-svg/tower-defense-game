#ifndef ROAD_H
#define ROAD_H
#include"map.h"
enum road_type
{
    ground_road,
    fly_road,
    stone_road
};
class Map;
class Road
{
   int road[200][2];
   int r_len;
   int type=ground_road;
public:
    Map* map;
    Road();
    int direction(const int i)const;
    int transtoxy(int d,int& _x,int& _y)const;
    void set_road(QVector<QVector<int>> r);
    int get_road(int x,int y)const{return road[x][y];};
    int get_roadlen()const{return r_len;};
    void set_type(int t){type=t;};
    int get_type()const{return type;};
};

#endif // ROAD_H
