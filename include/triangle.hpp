//#include "point.hpp"
#include "plane.hpp"

#pragma once

class Triangle{
public:

    Triangle(Point point_1, Point point_2, Point point_3): point_1_(point_1),
                                                           point_2_(point_2),
                                                           point_3_(point_3),
                                                           plane(point_1, point_2, point_3) {
    
    };
    
private:
    Point point_1_, point_2_, point_3_; // triangle points
    Plane plane; // the plane of our triangle
};