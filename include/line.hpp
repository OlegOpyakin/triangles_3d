#include "vector.hpp"
#include <cmath>
#pragma once

class Line{
public:
    Line(): direction_vector(Vector()), start_point(Point()) {}; //DEFAULT

    Line(Vector vector, Point point): // vector from start point to end point
        direction_vector(vector),
        start_point(point) {}; 
    Line(Point start_point, Point end_point):
        direction_vector(Vector(end_point, start_point)),
        start_point(start_point){};
    
    Vector GetDirectionVector(){
        return direction_vector;
    }

    Point GetStartPoint(){
        return start_point;
    }

    //void operator()(double X, double Y, double Z){} пока не знаю нужен или нет

private:
    Vector direction_vector;
    Point start_point;
};

bool LinesParallelCheck(Line line_1, Line line_2){
    return VectorEqual(line_1.GetDirectionVector(), line_2.GetDirectionVector());
}

