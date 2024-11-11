#include "triangle.hpp"
#include "approx_equal.hpp"
#include <iomanip>

Triangle::Triangle(Point point_1, Point point_2, Point point_3): point_1_(point_1),
                                                                 point_2_(point_2),
                                                                 point_3_(point_3),
                                                                 plane(point_1, point_2, point_3) {};
    
Plane Triangle::GetPlane() const{return plane;}

Triangle::~Triangle(){}

Point Triangle::get_point_1() const{return point_1_;}

Point Triangle::get_point_2() const{return point_2_;}

Point Triangle::get_point_3() const{return point_3_;}

// А что если треугольник касается этой самой плоскости?
bool Triangle::AllPointsRightOfPlane(Plane plane){
    std::cout << "\n" << plane.ValuePlaneEqual(point_1_) << "; "  << plane.ValuePlaneEqual(point_2_) << "; "  << plane.ValuePlaneEqual(point_3_) << std::endl; 
    if ((plane.ValuePlaneEqual(point_1_) > 0) and (plane.ValuePlaneEqual(point_2_) > 0) and (plane.ValuePlaneEqual(point_3_) > 0)){
            return true;
    }
    if ((plane.ValuePlaneEqual(point_1_) < 0) and (plane.ValuePlaneEqual(point_2_) < 0) and (plane.ValuePlaneEqual(point_3_) < 0)){
            return true;
    } 
    return false;
}

double Triangle::HalfPerimeter(){ 
    return (Vector(point_1_, point_2_).Len() + Vector(point_1_, point_3_).Len() + Vector(point_2_, point_3_).Len())/2;
}

double Triangle::Square(){    
    return sqrt(HalfPerimeter() * (HalfPerimeter() - Vector(point_1_, point_2_).Len()) * 
           (HalfPerimeter() - Vector(point_1_, point_3_).Len()) * (HalfPerimeter() - Vector(point_2_, point_3_).Len()));
}


// NEED FIX
// ACCURACY 10^{-14}
// MB ERRORS
bool Triangle::PointInTriangle(Point point){  
    double new_square = Triangle(point, point_2_, point_3_).Square() + Triangle(point, point_1_, point_2_).Square() +
                        Triangle(point, point_1_, point_3_).Square();
    if (ApproxEqual(Square(), new_square)) return true;
    return false;
}

double Triangle::test(Point point){
    return Triangle(point, point_2_, point_3_).Square() + Triangle(point, point_1_, point_2_).Square() +
           Triangle(point, point_1_, point_3_).Square();
}

std::pair<bool, std::pair<double, double>> Triangle::TriangleLineIntersection(Line line){
    // cut 1-2 & line
    std::pair<double, double> points(0,0);          // t1 and t2
    std::pair<bool, double> one_point_result;
    bool result_first_was_write = false;

//      FIX FIX FIX         FIX FIX FIX
//          разрашить редекларацию cut
//      FIX FIX FIZ         FIX FIX FIX

    Cut cut(get_point_1(), get_point_2());
    one_point_result = CutAndLineIntersection(cut, line);
    if (one_point_result.first) points.first = one_point_result.second;

    // cut 1-3 & line
    Cut cut1(get_point_1(), get_point_3());
    one_point_result = CutAndLineIntersection(cut1, line);
    if (one_point_result.first){
        if (result_first_was_write) points.second = one_point_result.second;
        else points.first = one_point_result.second;
    }

    // cut 2-3 & line
    Cut cut2(get_point_2(), get_point_3());
    one_point_result = CutAndLineIntersection(cut2, line);
    if (one_point_result.first) points.second = one_point_result.second;
    return std::make_pair(result_first_was_write, points);
}

bool TrianglesInOnePlanesIntersection(Triangle triangle_1, Triangle triangle_2){
    if (triangle_1.PointInTriangle(triangle_2.get_point_1())) return true;
    if (triangle_1.PointInTriangle(triangle_2.get_point_2())) return true;
    if (triangle_1.PointInTriangle(triangle_2.get_point_3())) return true;
    return false;
}