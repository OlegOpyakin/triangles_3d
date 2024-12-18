#include "line.hpp"
#include <cmath>
#include <utility>
#pragma once

class Cut{
public:
    Cut(); //DEFAULT

    Cut(Line &line, Point &start_point, Point &end_point); // vector from start point to end point

    Cut(Point start_point, Point end_point); // vector from start point to end point
    
    ~Cut() = default;

    Line GetLine () const;

    Point GetStartPoint () const;

    Point GetEndPoint () const;

    double Len() const;

    bool CorrectPoint(Line line, double s);

private:
    Line line;
    Point start_point, end_point;
};

std::pair <bool, double> CutAndLineIntersection(Cut cut, Line line_2); // find cut and line intersection
