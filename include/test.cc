#include "vector.hpp"
#include <iostream>

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
        D_ = - (A_ * point_1.GetX() + B_ * point_1.GetY() + C_ * point_1.GetZ()); 
    };

    double GetA() const { return A_; };
    double GetB() const { return B_; };
    double GetC() const { return C_; };
    double GetD() const { return D_; };

    double ValuePlaneEquel(Point point){
        return A_ * point.GetX() + B_ * point.GetY() + C_ * point.GetZ() + D_;
    }

    Vector GetVector() const { return normal_vector_; }

    void Print() {
        std::clog << "Plane: " << A_ << "x + " << B_ << "y + " << C_ << "z + " << D_ << "\nNormal " ;
        normal_vector_.Print();
    }

private:
    double A_, B_, C_, D_; //plane equasion coeffs Ax + By + Cz + D = 0
    Vector normal_vector_;
};

bool PlanesParallelCheck(Plane &plane_1, Plane &plane_2){           // to check if two planes are parallel
    return VectorEqual(plane_1.GetVector(), plane_2.GetVector()); // returns true if they are
}

Vector VectorPlanesIntersection(Plane plane_1, Plane plane_2){
    return VectorProduct(plane_1.GetVector(), plane_2.GetVector());
}

bool PlaneEqual(Plane plane_1, Plane plane_2){
    if(plane_1.GetA() / plane_1.GetD() != plane_2.GetA() / plane_2.GetD()) return false;
    if(plane_1.GetB() / plane_1.GetD() != plane_2.GetA() / plane_2.GetD()) return false;
    if(plane_1.GetC() / plane_1.GetD() != plane_2.GetA() / plane_2.GetD()) return false;
    return true;
} 

bool PlaneParallel(Plane plane_1, Plane plane_2){
    return VectorComplanar(plane_1.GetVector(), plane_2.GetVector());
}

void Find_Point(double A1, double B1, double C1, double D1,
                double A2, double B2, double C2, double D2){ // СХАЛЯВИМ
    Point P1(A1, B1, C1);
    Point P2(A2, B2, C2);
    Point P0(0,0,0);
    Vector N1(P0, P1);
    Vector N2(P0, P2);

    Vector direction = VectorProduct(N1,N2);
    double x,y,z;
    if (B1 != 0){ 
        x = 0;
        z = ((B2/B1) * D1 - D2)/(C2 - C1 * B2/B1);
        y = - (C1 * z + D1)/B1;
    }
    else if (C1 != 0){
        x = 0;
        y = ((C2/C1) * D1 - D2)/(B2 - B1 * C2/C1);
        z = - (B1 * y + D1)/C1;
    }
    else {
        z = 0;
        y = ((A2/A1) * D1 - D2)/(B2 - B1 * A2/A1);
        x = -(B1 * y + D1)/A1;
    }
    double A = direction.GetX();
    double B = direction.GetY();
    double C = direction.GetZ();

    double D = - (A*x + B*y + C*z);
    std::cout << "x: " << x << ";  y: " << y << ";  z: " << z << std::endl;
    std::cout << "A: " << A << ";  B: "<< B << ";  C: " << C << ";  D: " << D;
}

int main(){
    double A1 = 1;
    double B1 = 2;
    double C1 = 3;
    double D1 = 4;
              
    double A2 = 4;
    double B2 = 3;
    double C2 = 2;
    double D2 = 1; 

    Find_Point(A1, B1, C1, D1, A2, B2, C2, D2);
}