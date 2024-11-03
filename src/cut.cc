#include "cut.hpp"


Cut::Cut(): line(Line()), start_point(Point()), end_point(Point()) {}; //DEFAULT

// cut = line from start point to end point
Cut::Cut(Line line, Point start_point, Point end_point): line(line),
                                                         start_point(start_point),
                                                         end_point(end_point) {}; 

// cut = start point and end points
Cut::Cut(Point start_point, Point end_point): line(start_point, end_point),
                                              start_point(start_point),
                                              end_point(end_point) {}; 

Cut::~Cut(){}

Line Cut::GetLine () const { return line; }

Point Cut::GetStartPoint () const { return start_point; }

Point Cut::GetEndPoint () const { return end_point; }

double Cut::FindMinArg(){
    // x = x_0  + A * t => t = (x - x_0)/A
    return (start_point.GetX() - line.GetStartPoint().GetX())/line.GetDirectionVector().GetX();
}

double Cut::FindMaxArg(){
    // x = x_0  + A * t => t = (x - x_0)/A
    return (end_point.GetX() - line.GetStartPoint().GetX())/line.GetDirectionVector().GetX();
}

std::pair <bool, double> CutAndLineIntersection(Cut cut, Line line_2){    
    Line line_1 = cut.GetLine(); 

    if (LinesParallelCheck(line_1, line_2)) return std::make_pair(false, 0);

    Point point1 = line_1.GetStartPoint();
    Point point2 = line_2.GetStartPoint();
    Vector vector1 = line_1.GetDirectionVector();
    Vector vector2 = line_2.GetDirectionVector();

    double x1 = point1.GetX();
    double y1 = point1.GetY();
    double z1 = point1.GetZ();
    double x2 = point2.GetX();
    double y2 = point2.GetY();

    double A1 = vector1.GetX();
    double B1 = vector1.GetY();
    double C1 = vector1.GetZ();
    double A2 = vector2.GetX();
    double B2 = vector2.GetY();

    // у нас параметрическое уравнение прямой
    double t, s; // t - параметр первой прямой (отрезка), s - второй
    
    t = (y1 - y2 - B1 * ((x1 - x2)/A2))/((A1/A2) - B1);   
    s = (x1 - x2)/A2 + t*A1/A2 ;
    
    double t_min = cut.FindMinArg();
    double t_max = cut.FindMaxArg();

    if (t_min <= t and t <= t_max) return std::make_pair(true, s);
    else return std::make_pair(false, 0);
}