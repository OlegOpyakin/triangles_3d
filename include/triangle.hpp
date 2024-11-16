//#include "point.hpp"
#include "plane.hpp"
#include "cut.hpp"
#include <cmath>
#include "iostream"
#pragma once

class Triangle{
public:

    Triangle(Point point_1, Point point_2, Point point_3);

    Triangle();

    ~Triangle() = default;
    
    Plane GetPlane() const;

    Point get_point_1() const;

    Point get_point_2() const;

    Point get_point_3() const;

    bool AllPointsRightOfPlane(Plane plane);

    double HalfPerimeter();

    double Square();

    bool PointInTriangle(Point point);

    double test(Point point);

    std::pair<bool, std::pair<double, double>> TriangleLineIntersection(Line line);

    bool TriangleAndPlaneIntesection(Plane plane);

private:
    Point point_1_, point_2_, point_3_; // triangle points
    Plane plane; // the plane of our triangle
};


bool TrianglesInOnePlanesIntersection(Triangle triangle_1, Triangle triangle_2);