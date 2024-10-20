#include "vector.hpp"

#pragma once

class Plane{
public:
    Plane(): A_(0), B_(0), C_(0), D_(0), normal_vector_() {};

    Plane(Point point_1, Point point_2, Point point_3) {
        Vector vector_1_2(point_1, point_2);
        Vector vector_1_3(point_1, point_3);

        normal_vector_ = VectorProduct(vector_1_2, vector_1_3); // get normal vector to our plane
        
        A_ = normal_vector_.GetX();
        B_ = normal_vector_.GetY();
        C_ = normal_vector_.GetZ();
        D_ = - (A_ * point_1.GetX() + B_ * point_1.GetY() + C_ * point_1.GetZ()); //хз гпт подсказал, сам не уверен в правильности
    };

    double GetA() const { return A_; };
    double GetB() const { return B_; };
    double GetC() const { return C_; };
    double GetD() const { return D_; };

    Vector GetVector() const { return normal_vector_; }

    void Print() {
        std::clog << "Plane: " << A_ << "x + " << B_ << "y + " << C_ << "z + " << D_ << "\nNormal " ;
        normal_vector_.Print();
    }

private:
    double A_, B_, C_, D_; //plane equasion coeffs Ax + By + Cz + D = 0
    Vector normal_vector_;
};

bool PlanesParallelCheck(Plane plane_1, Plane plane_2){           // to check if two planes are parallel
    return VectorEqual(plane_1.GetVector(), plane_2.GetVector()); // returns true if they are
}

