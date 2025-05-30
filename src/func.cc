#include "func.hpp"

/*
*   There are 3 possible cases (mutually exclusive):
*   1. The planes in which the triangles lie are parallel (A special case is in the same plane)
*   2. The points of one triangle lie on one side of the plane of the other triangle
*   3. The intersection of triangles along the line of intersection of their planes
*/
bool CorrectPointOrder(double &t11, double &t12, double &t21, double &t22){ // only for point 1 < point 2
    // T11 T12 T21 T22
    if ((t11 <= t12) and (t12 < t21) and (t21 <= t22) and (ApproxEqual(t12, t21) == false)) return false;
    // T11 T12 T22 T21
    if ((t11 <= t12) and (t12 < t22) and (t22 <= t21) and (ApproxEqual(t12, t22) == false)) return false;
    // T12 T11 T21 T22
    if ((t12 <= t11) and (t11 < t21) and (t21 <= t22) and (ApproxEqual(t11, t21) == false)) return false;
    // T12 T11 T22 T21
    if ((t12 <= t11) and (t11 < t22) and (t22 <= t21) and (ApproxEqual(t11, t22) == false)) return false;
    return true;
}

bool ItPoint(Triangle &triangle_1){
    if (triangle_1.get_point_1().GetX() != triangle_1.get_point_2().GetX()) return false;
    if (triangle_1.get_point_1().GetX() != triangle_1.get_point_3().GetX()) return false;
    if (triangle_1.get_point_1().GetY() != triangle_1.get_point_2().GetY()) return false;
    if (triangle_1.get_point_2().GetY() != triangle_1.get_point_3().GetY()) return false;
    if (triangle_1.get_point_2().GetZ() != triangle_1.get_point_2().GetZ()) return false;
    if (triangle_1.get_point_2().GetZ() != triangle_1.get_point_3().GetZ()) return false;
    return true;
}

bool Intersection2Triangles(Triangle triangle_1, Triangle triangle_2){
    // check 2 points case
    if (ItPoint(triangle_1) and ItPoint(triangle_2)){
        if (triangle_1.get_point_1().GetX() != triangle_2.get_point_1().GetX()) return false;
        else return true;
    }
    

    if (ItPoint(triangle_2)){
        if (PlaneEqual(triangle_1.GetPlane(), triangle_2.GetPlane()) == false){ 
            return false;   // they are parallel, but not the same
        }
        else{
            return TrianglesInOnePlanesIntersection(triangle_1, triangle_2);   
        }
    }
    if (ItPoint(triangle_1)){
        if (PlaneEqual(triangle_2.GetPlane(), triangle_1.GetPlane()) == false){ 
            return false;   // they are parallel, but not the same
        }
        else{
            return TrianglesInOnePlanesIntersection(triangle_2, triangle_1);   
        }
    }
    // another cases

    if (PlaneParallel(triangle_1.GetPlane(), triangle_2.GetPlane())){     // 1 case
        if (PlaneEqual(triangle_1.GetPlane(), triangle_2.GetPlane()) == false){ 
            return false;   // they are parallel, but not the same
        }
        else{
            return TrianglesInOnePlanesIntersection(triangle_1, triangle_2);   
        }
    }   
    else{
        if (triangle_1.AllPointsRightOfPlane(triangle_2.GetPlane())){  
            return false; // the points of one triangle lie on one side of the plane of the other
        }
        else{
            // The intersection of triangles along the line of intersection of their planes
            // We already know that their plane of one triangle intersects with the second.
            // Let's intersect the straight line with both triangles. (let's check that it intersects with both triangles)
            // Let T1 be one of the points of intersection with the first, T2 be one of the points of intersection with the second.
            // If we get T2 T2 T1 T1 or T1 T1 T2 T2 => false
            // in all other cases => true
            Vector plane_intersection_vector = VectorPlanesIntersection(triangle_1.GetPlane(), triangle_2.GetPlane());   // The intersection vector of the planes
            Point plane_intesection_point = PointPlanesIntersection(triangle_1.GetPlane(), triangle_2.GetPlane());
            Line plane_intersection_line(plane_intersection_vector, plane_intesection_point);

            // pair (bool, t) t - parameters of the intersection of a straight line and planes
            std::pair<bool, std::pair<double, double>> intersection_points_1 = triangle_1.TriangleLineIntersection(plane_intersection_line); 
            std::pair<bool, std::pair<double, double>> intersection_points_2 = triangle_2.TriangleLineIntersection(plane_intersection_line); 
            // since in both cases the same line of intersection of planes with the same starting point was supplied, then
            // it is its parameters that we have obtained in pairs => it remains only to compare the order of the points
            if (intersection_points_1.first and intersection_points_2.first){
                double t11 = intersection_points_1.second.first;
                double t12 = intersection_points_1.second.second;
                double t21 = intersection_points_2.second.first;
                double t22 = intersection_points_2.second.second;
                
                if ((t11 == 2) or (t12 == 2) or (t21 == 2) or (t22 == 2)){  // we agreed that if the order of the points is not important, then t = 2
                    return true;
                }

                // checking the order of the points
                // The situations T2 T2 T1 T1 and T1 T1 T2 T2 should not come out
                if (CorrectPointOrder(t11, t12, t21, t22) and CorrectPointOrder(t21, t22, t11, t12)){
                    return true;
                }
            }
        }
    }
    return false;
}