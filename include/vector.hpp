#include "point.hpp"

#pragma once

class Vector{
public:
    Vector(): X_(0), Y_(0), Z_(0) {}; //DEFAULT

    Vector(Point point_start, Point point_end): // vector from start point to end point
        X_(point_end.GetX() - point_start.GetX()),
        Y_(point_end.GetY() - point_start.GetY()),
        Z_(point_end.GetZ() - point_start.GetZ()) {}; 
    
    Vector(double X, double Y, double Z): X_(X), Y_(Y), Z_(Z) {}

    double GetX() const { return X_; };
    double GetY() const { return Y_; };
    double GetZ() const { return Z_; };

    void Print() {
        std::clog << "Vector(" << X_ << ";" << Y_ << ";" << Z_ << ")\n";
    }

    //void operator()(double X, double Y, double Z){} пока не знаю нужен или нет

private:
    double X_, Y_, Z_;
};

bool VectorEqual(Vector vector_1, Vector vector_2) {
    if(vector_1.GetX() != vector_2.GetX()) return false;
    if(vector_1.GetY() != vector_2.GetY()) return false;
    if(vector_1.GetZ() != vector_2.GetZ()) return false;
    return true;
};

Vector VectorProduct(Vector& vector_1, Vector& vector_2) { // vector multiplication(returns vector)
    return Vector(vector_1.GetY() * vector_2.GetZ() - vector_1.GetZ() * vector_2.GetY(), // y1 * z2 - z1 * y2
                  vector_1.GetZ() * vector_2.GetX() - vector_1.GetX() * vector_2.GetZ(), // x2 * z1 - x1 * z2
                  vector_1.GetX() * vector_2.GetY() - vector_1.GetY() * vector_2.GetX());// x1 * y2 - x2 * y1
};

