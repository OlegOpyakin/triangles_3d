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

bool Triangle::PointInTriangle(Point point){  
    Vector vector_21(get_point_1(), get_point_2()); // BA
    Vector vector_32(get_point_2(), get_point_3()); // CB
    Vector vector_13(get_point_3(), get_point_1()); // AC
    Vector vector_p1(get_point_1(), point);         // PA
    Vector vector_p2(get_point_2(), point);         // PB
    Vector vector_p3(get_point_3(), point);         // PC
    

    Vector product1 = VectorProduct(vector_21, vector_p1);    // BA * PA
    Vector product2 = VectorProduct(vector_32, vector_p2);    // CB * PB
    Vector product3 = VectorProduct(vector_13, vector_p3);    // AC * PC

    if ((product1.GetX() >= -0.0001) and (product2.GetX() >= -0.0001) and (product3.GetX() >= -0.0001) and
        (product1.GetY() >= -0.0001) and (product2.GetY() >= -0.0001) and (product3.GetY() >= -0.0001) and
        (product1.GetZ() >= -0.0001) and (product2.GetZ() >= -0.0001) and (product3.GetZ() >= -0.0001)){
        return true;
    }
    if ((product1.GetX() < 0.0001) and (product2.GetX() < 0.0001) and (product3.GetX() < 0.0001) and
        (product1.GetY() < 0.0001) and (product2.GetY() < 0.0001) and (product3.GetY() < 0.0001) and
        (product1.GetZ() < 0.0001) and (product2.GetZ() < 0.0001) and (product3.GetZ() < 0.0001)){
        return true;
    }
    return false;
}

bool Triangle::TriangleAndPlaneIntesection(Plane &plane){
    if (PlaneParallel(GetPlane(), plane)) return false;
       
    Vector plane_intesection_vector = VectorPlanesIntersection(GetPlane(), plane);   // The intersection vector of the planes
    Point plane_intesection_point = PointPlanesIntersection(GetPlane(), plane);
    Line plane_intersection_line(plane_intesection_vector, plane_intesection_point);   

    // pair (bool, t) t - parameters of the intersection of a straight line and planes
    return TriangleLineIntersection(plane_intersection_line).first; 
}

std::pair<bool, std::pair<double, double>> Triangle::TriangleLineIntersection(Line &line){
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



bool TrianglesInOnePlanesIntersection(Triangle &triangle_1, Triangle &triangle_2){
    if (triangle_1.PointInTriangle(triangle_2.get_point_1())) return true;
    if (triangle_1.PointInTriangle(triangle_2.get_point_2())) return true;
    if (triangle_1.PointInTriangle(triangle_2.get_point_3())) return true;
    return false;
}