#include "approx_equal.hpp"

bool ApproxEqual(double a, double b){
    if ((a <= b + EPSILON) and (a >= b - EPSILON)) return true;
    return false;
}