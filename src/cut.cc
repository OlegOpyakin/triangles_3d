#include "cut.hpp"


Cut::Cut(): line(Line()), start_point(Point()), end_point(Point()) {} //DEFAULT

// cut = line from start point to end point
Cut::Cut(Line line, Point start_point, Point end_point): line(line),
                                                         start_point(start_point),
                                                         end_point(end_point) {}

// cut = start point and end points
Cut::Cut(Point start_point, Point end_point): line(start_point, end_point),
                                              start_point(start_point),
                                              end_point(end_point) {}

Cut::~Cut(){}

Line Cut::GetLine () const { return line; }

Point Cut::GetStartPoint () const { return start_point; }

Point Cut::GetEndPoint () const { return end_point; }


// ХЗ откуда тут минус - НУЖЕН И ТОЧКА
double Cut::FindMinArg(){
    // x = x_0  + A * t => t = (x - x_0)/A
    if (line.GetDirectionVector().GetX() != 0){
        return -(start_point.GetX() - line.GetStartPoint().GetX())/line.GetDirectionVector().GetX();
    }
    else if (line.GetDirectionVector().GetY() != 0){
        return -(start_point.GetY() - line.GetStartPoint().GetY())/line.GetDirectionVector().GetY();
    }
    else if (line.GetDirectionVector().GetZ() != 0){
        return -(start_point.GetZ() - line.GetStartPoint().GetZ())/line.GetDirectionVector().GetZ();
    }
}

double Cut::FindMaxArg(){
    // x = x_0  + A * t => t = (x - x_0)/A
    if (line.GetDirectionVector().GetX() != 0){
        return -(end_point.GetX() - line.GetStartPoint().GetX())/line.GetDirectionVector().GetX();
    }
    else if (line.GetDirectionVector().GetY() != 0){
        return -(end_point.GetY() - line.GetStartPoint().GetY())/line.GetDirectionVector().GetY();
    }
    else if (line.GetDirectionVector().GetZ() != 0){
        return -(end_point.GetZ() - line.GetStartPoint().GetZ())/line.GetDirectionVector().GetZ();
    }
}

    std::pair <bool, double> CutAndLineIntersection(Cut cut, Line line_2){    

        Line line_1 = cut.GetLine(); 


        Point point1 = line_1.GetStartPoint();
        Point point2 = line_2.GetStartPoint();
        Vector vector1 = line_1.GetDirectionVector();
        Vector vector2 = line_2.GetDirectionVector();

        double x1 = point1.GetX();
        double y1 = point1.GetY();
        double z1 = point1.GetZ();
        double x2 = point2.GetX();
        double y2 = point2.GetY();
        double z2 = point2.GetZ();

        double A1 = vector1.GetX();
        double B1 = vector1.GetY();
        double C1 = vector1.GetZ();
        double A2 = vector2.GetX();
        double B2 = vector2.GetY();
        double C2 = vector2.GetZ();

        // у нас параметрическое уравнение прямой
        double t, s; // t - параметр первой прямой (отрезка), s - второй
        
        // проверим на параллельность
        double denom = A1 * B2 + A2 * B1;
        if (denom == 0){
            denom = B1 * C2 - B2 * C1;
            if (denom == 0) return std::make_pair(false, 0); // параллельны
            else{
                t = ((x2 - x1) * B2 - (y2 - y1) * A2) / denom;
                s = ((x2 - x1) * B1 - (y2 - y1) * A1) / denom;
            }
        }
        else{
            t = ((x2 -x1) * B2 - (y2 - y1) * A2) / denom;
            s = ((x2 -x1) * B1 - (y2 - y1) * A1) / denom;
        }

        double t_min = cut.FindMinArg();
        double t_max = cut.FindMaxArg();

// код написан так что min всегда = 0, а max = 1;
/*
        if (t_min <= t_max){
            if (t_min <= t and t <= t_max) return std::make_pair(true, s);
            else return std::make_pair(false, 0);
        }
        else{
            if (t_max <= t and t <= t_min) return std::make_pair(true, s);
            else return std::make_pair(false, 0);
        }
*/
        if (-1 <= t and t <= 1) return std::make_pair(true, s);
        else return std::make_pair(false, 0);
    }