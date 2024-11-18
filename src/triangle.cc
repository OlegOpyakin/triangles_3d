#include "triangle.hpp"
#include "approx_equal.hpp"
#include <iomanip>

Triangle::Triangle(Point point_1, Point point_2, Point point_3): point_1_(point_1),
                                                                 point_2_(point_2),
                                                                 point_3_(point_3),
                                                                 plane(point_1, point_2, point_3) {};
    
Plane Triangle::GetPlane() const {return plane;}

Point Triangle::get_point_1() const {return point_1_;}

Point Triangle::get_point_2() const {return point_2_;}

Point Triangle::get_point_3() const {return point_3_;}

bool Triangle::AllPointsRightOfPlane(Plane plane){
    if (plane.SignOfPointPosition(point_1_) and plane.SignOfPointPosition(point_2_) and plane.SignOfPointPosition(point_3_)){
            return true;
    }
    if (plane.SignOfPointPosition(point_1_) == false and (plane.SignOfPointPosition(point_2_) == false) and (plane.SignOfPointPosition(point_3_) == false)){
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

bool Triangle::TriangleAndPlaneIntesection(Plane plane){
    if (PlaneParallel(GetPlane(), plane)) return false;
       
    Vector plane_intesection_vector = VectorPlanesIntersection(GetPlane(), plane);   // The intersection vector of the planes
    Point plane_intesection_point = PointPlanesIntersection(GetPlane(), plane);
    Line plane_intersection_line(plane_intesection_vector, plane_intesection_point);   

    // pair (bool, t) t - parameters of the intersection of a straight line and planes
    return TriangleLineIntersection(plane_intersection_line).first; 
}

std::pair<bool, std::pair<double, double>> Triangle::TriangleLineIntersection(Line line){
    // cut 1-2 & line
    std::pair<double, double> points(0,0);          // t1 and t2
    std::pair<bool, double> one_point_result;
    bool result_first_was_write = false;
    

    if (LineEqual(Cut(get_point_1(), get_point_2()).GetLine(), line)){
        one_point_result = std::make_pair(true, -1);
    }
    else{
        one_point_result = CutAndLineIntersection(Cut(get_point_1(), get_point_2()), line);
    }
    if (one_point_result.first){
        points.first = one_point_result.second;
        result_first_was_write = true;
    }

    // cut 1-3 & line

    
    if (LineEqual(Cut(get_point_1(), get_point_3()).GetLine(), line)){
        if (result_first_was_write){
            one_point_result = std::make_pair(true, 0);
        }
        else{
            one_point_result = std::make_pair(true, -1);
        }
    }
    else{
        one_point_result = CutAndLineIntersection(Cut(get_point_1(), get_point_3()), line);
    }    if (one_point_result.first){
        if (result_first_was_write){
            points.second = one_point_result.second;
        }
        else{
            points.first = one_point_result.second;
            result_first_was_write = true;
        }
    }
    // cut 2-3 & line
    if (LineEqual(Cut(get_point_2(), get_point_3()).GetLine(), line)){
        one_point_result = std::make_pair(true, 0);
    }
    else{
        one_point_result = CutAndLineIntersection(Cut(get_point_2(), get_point_3()), line);
    }
    if (one_point_result.first) points.second = one_point_result.second;
    return std::make_pair(result_first_was_write, points);
}



bool TrianglesInOnePlanesIntersection(Triangle triangle_1, Triangle triangle_2){
    if (triangle_1.PointInTriangle(triangle_2.get_point_1())) return true;
    if (triangle_1.PointInTriangle(triangle_2.get_point_2())) return true;
    if (triangle_1.PointInTriangle(triangle_2.get_point_3())) return true;
    return false;
}