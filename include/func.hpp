#include "triangle.hpp"

#pragma once

/*
*   Возможны 3 случая (взаимоисключ):
*   1. Плоскости, в которых лежат треугольники, параллельны (Частный случай - в одной плоскости)
*   2. Точки одного треугольника лежат по одну сторону от плоскости другого треугольника 
*   3.  Пересечение треугольников по линии пересечения их плоскостей
*/

bool Intersection2Triangles(Triangle triangle_1, Triangle triangle_2){
    if (PlaneParallel(triangle_1.GetPlane(), triangle_2.GetPlane())){     // 1-ый случай
        if (PlaneEqual(triangle_1.GetPlane(), triangle_2.GetPlane()) == false){ 
            return false;   // они параллельны, но не совпадают;
        }
        else{
            return TrianglesInOnePlanesIntersection(triangle_1, triangle_2); // Если в одной плоскости
        }
    }
    else{
        if (triangle_1.AllPointsRightOfPlane(triangle_2.GetPlane())){  
            return false; // точки одного треугольника лежат по одну сторону от плоскости другого
        }
        else{
            // Пересечение треугольников по линии пересечения их плоскостей 
            // Мы уже знаем что их плоскость одного треугольника пересекается со вторым.
            // Пересечем прямую с обоими треугольниками. (проверим что она пересекается с обоими треугольниками)
            // Пусть Т1 - одна из точек пересечения с первым, Т2 - Одна из точек пересечения со вторым.
            // Если получим Т2 Т2 Т1 Т1 или Т1 Т1 Т2 Т2 => false 
            // в остальных случаях true
            Vector plane_intesection_vector = VectorPlanesIntersection(triangle_1.GetPlane(), triangle_2.GetPlane());   // Вектор пересечения из плоскостей
            if (triangle_1.TriangleVectorIntersection(plane_intesection_vector) == true and 
                triangle_2.TriangleVectorIntersection(plane_intesection_vector) == true){
                // проверяем порядок точек

            }
        }
    } 
}