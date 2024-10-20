#include <stdint.h> 
#include <iostream>

#pragma once

using i_32 = int32_t;

class Point{
public:
    Point():X_(0.0), Y_(0.0), Z_(0.0) {}; //DEFAULT
    
    Point(double X, double Y, double Z):X_(X), Y_(Y), Z_(Z) {};

    ~Point() {};

    void SetX(const double X) { X_ = X; };
    void SetY(const double Y) { Y_ = Y; };
    void SetZ(const double Z) { Z_ = Z; };

    double GetX() const { return X_; };
    double GetY() const { return Y_; };
    double GetZ() const { return Z_; };

    void Print() {
        std::clog << "Point(" << X_ << ";" << Y_ << ";" << Z_ << ")\n";
    }
private:
    double X_, Y_, Z_;
};