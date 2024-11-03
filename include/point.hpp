#include <stdint.h> 
#include <iostream>

#pragma once

using i_32 = int32_t;

class Point{
public:
    Point(); //DEFAULT
    
    Point(double X, double Y, double Z);

    ~Point();

    void SetX(const double X);
    void SetY(const double Y);
    void SetZ(const double Z);

    double GetX() const;
    double GetY() const;
    double GetZ() const;

    void Print();
private:
    double X_, Y_, Z_;
};