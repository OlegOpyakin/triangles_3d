#include "cut.hpp"


Cut::Cut(): line(Line()), start_point(Point()), end_point(Point()) {} //DEFAULT

// cut = line from start point to end point
Cut::Cut(Line &line, Point &start_point, Point &end_point): line(line),
                                                         start_point(start_point),
                                                         end_point(end_point) {}

// cut = start point and end points
Cut::Cut(Point start_point, Point end_point): line(start_point, end_point),
                                              start_point(start_point),
                                              end_point(end_point) {}

Line Cut::GetLine () const { return line; }

Point Cut::GetStartPoint () const { return start_point; }

Point Cut::GetEndPoint () const { return end_point; }

double Cut::Len() const{
    return sqrt((start_point.GetX() - end_point.GetX()) * (start_point.GetX() - end_point.GetX()) + 
            (start_point.GetY() - end_point.GetY()) * (start_point.GetY() - end_point.GetY()) + 
            (start_point.GetZ() - end_point.GetZ()) * (start_point.GetZ() - end_point.GetZ()));
}

bool Cut::CorrectPoint(Line line, double s){
    Point point;
    point.SetX(line.GetStartPoint().GetX() + s * line.GetDirectionVector().GetX());
    point.SetY(line.GetStartPoint().GetY() + s * line.GetDirectionVector().GetY());
    point.SetZ(line.GetStartPoint().GetZ() + s * line.GetDirectionVector().GetZ());

    Cut cut1(GetStartPoint(), point);
    Cut cut2(point, GetEndPoint());    

    return ApproxEqual(Len(), cut1.Len() + cut2.Len());
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

    // We have a parametric equation of a straight line
    double s; // ts is the parameter of a parametrically defined line; |s| <= 1 
        
    // let's check for parallelism
    double denom = A1 * B2 - A2 * B1;
    if (denom == 0){
        denom = B1 * C2 - B2 * C1;
        if (denom == 0) {
            if (x1 == x2 and y1 == y2 and z1 == z2){
                return std::make_pair(true, 2); // The order of the points will not be important to us
            }
            else if (((x1-x2)*B1  == (y1-y2)*A1) and ((x1-x2)*C1  == (z1-z2)*A1)){
                return std::make_pair(true, 2); // The order of the points will not be important to us
            }
            else{
                return std::make_pair(false, 0); // parallel
            }
        }
        else{
            s = ((x2 - x1) * B1 - (y2 - y1) * A1) / denom;
        }
    }
    else{
        s = ((x2 -x1) * B1 - (y2 - y1) * A1) / denom;
    }


    // but let's add an additional check
    if (cut.CorrectPoint(line_2, s)){
        return std::make_pair(true, s);
    }
    
    return std::make_pair(false, 0);
}