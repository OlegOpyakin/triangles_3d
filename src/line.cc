#include "line.hpp"

Line::Line(): direction_vector(Vector()),
              start_point(Point()) {} //DEFAULT

// line = vector + start point
Line::Line(Vector vector, Point point): direction_vector(vector),
                                        start_point(point) {}

Line::Line(Point start_point, Point end_point): direction_vector(Vector(end_point, start_point)),
                                                start_point(start_point){}
    
Line::~Line(){}

Vector Line::GetDirectionVector() const { return direction_vector; }

Point Line::GetStartPoint() const { return start_point; }

bool LinesParallelCheck(Line line_1, Line line_2){
    return VectorEqual(line_1.GetDirectionVector(), line_2.GetDirectionVector());
}