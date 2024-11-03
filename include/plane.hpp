#include "vector.hpp"

#pragma once

class Plane{
public:
    Plane();

    Plane(Point point_1, Point point_2, Point point_3);

    ~Plane();

    double GetA() const;
    double GetB() const;
    double GetC() const;
    double GetD() const;

    double ValuePlaneEquel(Point point);
    Vector GetVector() const;

    void Print();

private:
    double A_, B_, C_, D_; //plane equasion coeffs Ax + By + Cz + D = 0
    Vector normal_vector_;
};

bool PlanesParallelCheck(Plane &plane_1, Plane &plane_2);           // to check if two planes are parallel

Vector VectorPlanesIntersection(Plane plane_1, Plane plane_2);

Point PointPlanesIntersection(Plane plane_1, Plane plane_2);

bool PlaneEqual(Plane plane_1, Plane plane_2);

bool PlaneParallel(Plane plane_1, Plane plane_2);