//#include "point.hpp"
#include "plane.hpp"
#include <cmath>

#pragma once

class Triangle{
public:

    Triangle(Point point_1, Point point_2, Point point_3): point_1_(point_1),
                                                           point_2_(point_2),
                                                           point_3_(point_3),
                                                           plane(point_1, point_2, point_3) {
    
    };
    
    Plane GetPlane(){
        return plane;
    }

    Point get_point_1(){
        return point_1_;
    }

    Point get_point_2(){
        return point_2_;
    }

    Point get_point_3(){
        return point_3_;
    }

    bool AllPointsRightOfPlane(Plane plane){
        if (plane.ValuePlaneEquel(point_1_) != plane.ValuePlaneEquel(point_2_)) return false;
        if (plane.ValuePlaneEquel(point_1_) != plane.ValuePlaneEquel(point_3_)) return false;
        return true;
    }

    double HalfPerimeter(){ //*
        return (Vector(point_1_, point_2_).Len() + Vector(point_1_, point_3_).Len() + Vector(point_2_, point_3_).Len())/2;
    }

    double Square(){    //*
        return sqrt(HalfPerimeter() * (HalfPerimeter() - Vector(point_1_, point_2_).Len()) * 
        (HalfPerimeter() - Vector(point_1_, point_3_).Len()) * (HalfPerimeter() - Vector(point_2_, point_3_).Len()));
    }

    bool PointInTriangle(Point point){  //*
        if (Square() == Triangle(point, point_2_, point_3_).Square() + Triangle(point, point_1_, point_2_).Square() +
        Triangle(point, point_1_, point_3_).Square()) return true;
        return false;
    }

    bool TriangleVectorIntersection(Vector vector){

        
    }

private:
    Point point_1_, point_2_, point_3_; // triangle points
    Plane plane; // the plane of our triangle
};


bool TrianglesInOnePlanesIntersection(Triangle triangle_1, Triangle triangle_2){
    if (triangle_1.PointInTriangle(triangle_2.get_point_1()) == true) return true;
    if (triangle_1.PointInTriangle(triangle_2.get_point_2()) == true) return true;
    if (triangle_1.PointInTriangle(triangle_2.get_point_3()) == true) return true;
    return false;
}