#include "triangle.hpp"

Triangle::Triangle(Point point_1, Point point_2, Point point_3): point_1_(point_1),
                                                                 point_2_(point_2),
                                                                 point_3_(point_3),
                                                                 plane(point_1, point_2, point_3) {};
    
Plane Triangle::GetPlane() const{return plane;}

Triangle::~Triangle(){}

Point Triangle::get_point_1() const{return point_1_;}

Point Triangle::get_point_2() const{return point_2_;}

Point Triangle::get_point_3() const{return point_3_;}

bool Triangle::AllPointsRightOfPlane(Plane plane){
    if (plane.ValuePlaneEquel(point_1_) != plane.ValuePlaneEquel(point_2_)) return false;
    if (plane.ValuePlaneEquel(point_1_) != plane.ValuePlaneEquel(point_3_)) return false;
    return true;
}

double Triangle::HalfPerimeter(){ 
    return (Vector(point_1_, point_2_).Len() + Vector(point_1_, point_3_).Len() + Vector(point_2_, point_3_).Len())/2;
}

double Triangle::Square(){    
    return sqrt(HalfPerimeter() * (HalfPerimeter() - Vector(point_1_, point_2_).Len()) * 
           (HalfPerimeter() - Vector(point_1_, point_3_).Len()) * (HalfPerimeter() - Vector(point_2_, point_3_).Len()));
}

bool Triangle::PointInTriangle(Point point){  
    if (Square() == Triangle(point, point_2_, point_3_).Square() + Triangle(point, point_1_, point_2_).Square() +
        Triangle(point, point_1_, point_3_).Square()) {
            return true;
        }
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
//          разрашить редкарацию cut
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