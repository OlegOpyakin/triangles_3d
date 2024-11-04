#include "vector.hpp"



Vector::~Vector() {}

double Vector::GetX() const { return X_; };
double Vector::GetY() const { return Y_; };
double Vector::GetZ() const { return Z_; };

void Vector::Print() {
    std::clog << "Vector(" << X_ << ";" << Y_ << ";" << Z_ << ")\n";
}

double Vector::Len(){   //*
    return sqrt(X_*X_ + Y_*Y_ + Z_*Z_);
}

bool VectorEqual(Vector vector_1, Vector vector_2) {
    if(vector_1.GetX() != vector_2.GetX()) return false;
    if(vector_1.GetY() != vector_2.GetY()) return false;
    if(vector_1.GetZ() != vector_2.GetZ()) return false;
    return true;
}

Vector VectorProduct(Vector vector_1, Vector vector_2) { // vector multiplication(returns vector)
    return Vector(vector_1.GetY() * vector_2.GetZ() - vector_1.GetZ() * vector_2.GetY(), // y1 * z2 - z1 * y2
                  vector_1.GetZ() * vector_2.GetX() - vector_1.GetX() * vector_2.GetZ(), // x2 * z1 - x1 * z2
                  vector_1.GetX() * vector_2.GetY() - vector_1.GetY() * vector_2.GetX());// x1 * y2 - x2 * y1
}

bool VectorColliniar(Vector vector_1, Vector vector_2){
    if (VectorProduct(vector_1, vector_2).Len() == 0){
        return true;
    }
    return false;
}