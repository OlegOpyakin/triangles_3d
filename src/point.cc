#include "point.hpp"

Point::Point(): X_(0.0), Y_(0.0), Z_(0.0) {}; //DEFAULT
    
Point::Point(double X, double Y, double Z):X_(X), Y_(Y), Z_(Z) {};

Point::~Point() {};

void Point::SetX(const double X) { X_ = X; };
void Point::SetY(const double Y) { Y_ = Y; };
void Point::SetZ(const double Z) { Z_ = Z; };

double Point::GetX() const { return X_; };
double Point::GetY() const { return Y_; };
double Point::GetZ() const { return Z_; };

void Point::Print() {
    std::clog << "Point(" << X_ << ";" << Y_ << ";" << Z_ << ")\n";
}