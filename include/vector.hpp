#include "point.hpp"
#include <cmath>
#pragma once

class Vector{
public:
    Vector(): X_(0), Y_(0), Z_(0) {}; //DEFAULT

    Vector(Point point_start, Point point_end); // vector from start point to end point
    
    Vector(double X, double Y, double Z);

    ~Vector();

    double GetX() const;
    double GetY() const;
    double GetZ() const;

    void Print();

    double Len();

    //void operator()(double X, double Y, double Z){} пока не знаю нужен или нет

private:
    double X_, Y_, Z_;
};

bool VectorEqual(Vector vector_1, Vector vector_2);

Vector VectorProduct(Vector vector_1, Vector vector_2);  // vector multiplication(returns vector)

bool VectorColliniar(Vector vector_1, Vector vector_2);