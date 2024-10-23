#include "vector.hpp"
#include <cmath>
#pragma once

class Line{
public:
    Line(): A_(0), B_(0), C_(0) {}; //DEFAULT

    Line(Point point_start, Point point_end): // vector from start point to end point
        X_(point_end.GetX() - point_start.GetX()),
        Y_(point_end.GetY() - point_start.GetY()),
        Z_(point_end.GetZ() - point_start.GetZ()) {}; 
    
    Line(double X, double Y, double Z): X_(X), Y_(Y), Z_(Z) {}

    double GetX() const { return X_; };
    double GetY() const { return Y_; };
    double GetZ() const { return Z_; };

    void Print() {
        std::clog << "Vector(" << X_ << ";" << Y_ << ";" << Z_ << ")\n";
    }

    double Len(){   //*
        return sqrt(X_*X_ + Y_*Y_ + Z_*Z_);
    }

    bool PointBelongsVector(Point point){
        
    }
    //void operator()(double X, double Y, double Z){} пока не знаю нужен или нет

private:
    double A_, B_, C_;
};

