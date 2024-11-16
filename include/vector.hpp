#include "point.hpp"
#include <cmath>
#pragma once

class Vector{
public:

    // NEED RAPAIR!!!
    // Have not realization in .cc

    Vector(); //DEFAULT

    // vector from start point to end point
    Vector(Point point_start, Point point_end);
        
    Vector(double X, double Y, double Z);

    ~Vector() = default;

    double GetX() const;
    double GetY() const;
    double GetZ() const;

    void SetX(const double X);
    void SetY(const double Y);
    void SetZ(const double Z);
    
    void Print();

    double Len();

    //void operator()(double X, double Y, double Z){} пока не знаю нужен или нет

private:
    double X_, Y_, Z_;
};

bool VectorEqual(Vector vector_1, Vector vector_2);

Vector VectorProduct(Vector vector_1, Vector vector_2);  // vector multiplication(returns vector)

bool VectorColliniar(Vector vector_1, Vector vector_2);