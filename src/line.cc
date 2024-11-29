#include "line.hpp"
#include <iostream>

Line::Line(): direction_vector(Vector()),
              start_point(Point()) {} //DEFAULT

// line = vector + start point
Line::Line(Vector &vector, Point &point): direction_vector(vector),
                                        start_point(point) {}

Line::Line(Point &start_point, Point &end_point): direction_vector(Vector(end_point, start_point)),
                                                start_point(start_point){}
    
Vector Line::GetDirectionVector() const { return direction_vector; }

Point Line::GetStartPoint() const { return start_point; }

bool LinesParallelCheck(Line &line_1, Line &line_2){
    return VectorEqual(line_1.GetDirectionVector(), line_2.GetDirectionVector());
}
bool LineEqual(Line line_1, Line line_2){
    if (LinesParallelCheck(line_1, line_2)){
        Point point_1 = line_1.GetStartPoint();
        Point point_2 = line_2.GetStartPoint();
        Vector direction_vector = line_1.GetDirectionVector();
        if (ApproxEqual((point_1.GetX() - point_2.GetX()) * direction_vector.GetY(), (point_1.GetY() - point_2.GetY()) * direction_vector.GetX()) == false){
            return false;
        }
        if (ApproxEqual((point_1.GetX() - point_2.GetX()) * direction_vector.GetZ(), (point_1.GetZ() - point_2.GetZ()) * direction_vector.GetX()) == false){
            return false;
        }
        if (ApproxEqual((point_1.GetY() - point_2.GetY()) * direction_vector.GetZ(), (point_1.GetZ() - point_2.GetZ()) * direction_vector.GetY()) == false){
            return false;
        }
        return true;
    }
    return false;
}