#include "vector.hpp"
#include <cmath>
#include "approx_equal.hpp"
#pragma once

class Line{
public:
    Line(); //DEFAULT

    Line(Vector &vector, Point &point); // vector from start point to end point

    Line(Point &start_point, Point &end_point);

    ~Line() = default;

    Vector GetDirectionVector() const;

    Point GetStartPoint() const;
    //void operator()(double X, double Y, double Z){} пока не знаю нужен или нет

private:
    Vector direction_vector;
    Point start_point;
};

bool LinesParallelCheck(Line &line_1, Line &line_2);


bool LineEqual(Line line_1, Line line_2);