#include "vector.hpp"

#pragma once

class Plane{
public:
    Plane();

    Plane(Point &point_1, Point &point_2, Point &point_3);

    ~Plane() = default;

    double GetA() const;
    double GetB() const;
    double GetC() const;
    double GetD() const;

    void SetA(const double &A);
    void SetB(const double &B);
    void SetC(const double &C);
    void SetD(const double &D);


    double SignOfPointPosition(Point &point);
    Vector GetVector() const;

    void Print();

private:
    double A_ = 0, B_ = 0, C_ = 0, D_ = 0; //plane equasion coeffs Ax + By + Cz + D = 0
    Vector normal_vector_;
};


Vector VectorPlanesIntersection(Plane plane_1, Plane plane_2);

Point PointPlanesIntersection(Plane plane_1, Plane plane_2);

bool PlaneEqual(Plane plane_1, Plane plane_2);

bool PlaneParallel(Plane plane_1, Plane plane_2);