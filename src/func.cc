#include "func.hpp"

/*
*   Возможны 3 случая (взаимоисключ):
*   1. Плоскости, в которых лежат треугольники, параллельны (Частный случай - в одной плоскости)
*   2. Точки одного треугольника лежат по одну сторону от плоскости другого треугольника 
*   3.  Пересечение треугольников по линии пересечения их плоскостей
*/
bool CorrectPointOrder(double t11, double t12, double t21, double t22){ // only for point 1 < point 2
    // T11 T12 T21 T22
    if (t11 <= t12 and t12 < t21 and t21 <= t22) return false;
    // T11 T12 T22 T21
    if (t11 <= t12 and t12 < t22 and t22 <= t21) return false;
    // T12 T11 T21 T22
    if (t12 <= t11 and t11 < t21 and t21 <= t22) return false;
    // T12 T11 T22 T21
    if (t12 <= t11 and t11 < t22 and t22 <= t21) return false;
    return true;
}

bool Intersection2Triangles(Triangle triangle_1, Triangle triangle_2){
    if (PlaneParallel(triangle_1.GetPlane(), triangle_2.GetPlane())){     // 1-ый случай
        if (PlaneEqual(triangle_1.GetPlane(), triangle_2.GetPlane()) == false){ 
            return false;   // они параллельны, но не совпадают;
        }
        else{
            //FUCK
            return TrianglesInOnePlanesIntersection(triangle_1, triangle_2);   
        }
    }
    else{
        if (triangle_1.AllPointsRightOfPlane(triangle_2.GetPlane())){  
            return false; // точки одного треугольника лежат по одну сторону от плоскости другого
        }
        else{
            std::cout << "PRINT" << std::endl;

            // Пересечение треугольников по линии пересечения их плоскостей 
            // Мы уже знаем что их плоскость одного треугольника пересекается со вторым.
            // Пересечем прямую с обоими треугольниками. (проверим что она пересекается с обоими треугольниками)
            // Пусть Т1 - одна из точек пересечения с первым, Т2 - Одна из точек пересечения со вторым.
            // Если получим Т2 Т2 Т1 Т1 или Т1 Т1 Т2 Т2 => false 
            // в остальных случаях true
            Vector plane_intesection_vector = VectorPlanesIntersection(triangle_1.GetPlane(), triangle_2.GetPlane());   // Вектор пересечения из плоскостей
            Point plane_intesection_point = PointPlanesIntersection(triangle_1.GetPlane(), triangle_2.GetPlane());
            Line plane_intersection_line(plane_intesection_vector, plane_intesection_point);   

            // пара (bool, t) t - параметры пересечения прямой и плоскостей
            std::pair<bool, std::pair<double, double>> intersection_points_1 = triangle_1.TriangleLineIntersection(plane_intersection_line); 
            std::pair<bool, std::pair<double, double>> intersection_points_2 = triangle_2.TriangleLineIntersection(plane_intersection_line); 
            // поскольку в оба случая подавалась одна и та же прямая пересечения плоскостей с одной и той же начальной точкой, то
            // именно ее параметры мы получили в парах => остается лишь сравнеить  порядок точек
            std::cout << intersection_points_1.first << "   " << intersection_points_2.first << std::endl;
            if (intersection_points_1.first and intersection_points_2.first){
                printf("HERE\n");
                double t11 = intersection_points_1.second.first;
                double t12 = intersection_points_1.second.second;
                double t21 = intersection_points_2.second.first;
                double t22 = intersection_points_2.second.second;
                // Проверяем порядок точек
                // не должны выйти ситуации Т2 Т2 Т1 Т1 и Т1 Т1 Т2 Т2

                // Алгоритм: между двумя меньшими точками Т1 и Т2 не может лежать точка:
                // T1, если min_T1 < min_T2
                // T2, если min_T1 > min_T2

                // T11 T12 T21 T22
                if (CorrectPointOrder(t11, t12, t21, t22) and CorrectPointOrder(t21, t22, t11, t12)){
                    return true;
                }
            }
        }
    }
    return false;
}