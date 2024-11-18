#include "plane.hpp"

Plane::Plane(): A_(0), B_(0), C_(0), D_(0), normal_vector_() {}

Plane::Plane(Point &point_1, Point &point_2, Point &point_3) {
    Vector vector_1_2(point_1, point_2);
    Vector vector_1_3(point_1, point_3);

    normal_vector_ = VectorProduct(vector_1_2, vector_1_3); // get normal vector to our plane
        
    A_ = normal_vector_.GetX();
    B_ = normal_vector_.GetY();
    C_ = normal_vector_.GetZ();
    D_ = - (A_ * point_1.GetX() + B_ * point_1.GetY() + C_ * point_1.GetZ()); 
}

double Plane::GetA() const { return A_; }
double Plane::GetB() const { return B_; }
double Plane::GetC() const { return C_; }
double Plane::GetD() const { return D_; }

void Plane::SetA(const double &A) { A_ = A; }
void Plane::SetB(const double &B) { B_ = B; }
void Plane::SetC(const double &C) { C_ = C; }
void Plane::SetD(const double &D) { D_ = D; }

double Plane::SignOfPointPosition(Point &point){
    if ((A_ * point.GetX() + B_ * point.GetY() + C_ * point.GetZ() + D_) > 0) return true;
    return false;
}

Vector Plane::GetVector() const { return normal_vector_; }

void Plane::Print() {
    std::clog << "Plane: " << A_ << "x + " << B_ << "y + " << C_ << "z + " << D_ << "\nNormal " ;
    normal_vector_.Print();
}



Vector VectorPlanesIntersection(Plane plane_1, Plane plane_2){
    return VectorProduct(plane_1.GetVector(), plane_2.GetVector());
}

Point PointPlanesIntersection(Plane plane_1, Plane plane_2){
    double A1 = plane_1.GetA();
    double B1 = plane_1.GetB();
    double C1 = plane_1.GetC();
    double D1 = plane_1.GetD();
    double A2 = plane_2.GetA();
    double B2 = plane_2.GetB();
    double C2 = plane_2.GetC();
    double D2 = plane_2.GetD();
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
    Point intersection_point(x,y,z);
    return intersection_point;
}

bool PlaneEqual(Plane plane_1, Plane plane_2){
    if (plane_1.GetD() * plane_2.GetA() != plane_2.GetD() * plane_1.GetA()) return false;
    if (plane_1.GetD() * plane_2.GetB() != plane_2.GetD() * plane_1.GetB()) return false;
    if (plane_1.GetD() * plane_2.GetC() != plane_2.GetD() * plane_1.GetC()) return false;
    return true;
} 

bool PlaneParallel(Plane plane_1, Plane plane_2){
    return VectorColliniar(plane_1.GetVector(), plane_2.GetVector());
}