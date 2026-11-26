#ifndef POINT_H
#define POINT_H
#include<QPainter>

class Point
{

public:
    Point(double x=-1,double y=-1);
    double px;
    double py;
    double dis(const Point &p) const;
};

#endif // POINT_H
