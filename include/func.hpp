#include "OctTree.hpp"
#include <iostream> 

#pragma once

bool CorrectPointOrder(double t11, double t12, double t21, double t22); // only for point 1 < point 2

bool Intersection2Triangles(Triangle triangle_1, Triangle triangle_2);