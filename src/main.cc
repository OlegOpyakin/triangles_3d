#include "func.hpp"
#include <vector>
#include <iostream>

int main(){
    const int max = 1000000;
    int N;
    double x, y, z;
    std::vector<Triangle> triangles;
    int count = 0;

    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::cin >> x >> y >> z;
        Point point1(x, y, z);
        std::cin >> x >> y >> z;
        Point point2(x, y, z);
        std::cin >> x >> y >> z;
        Point point3(x, y, z);
        triangles.push_back(Triangle(point1, point2, point3));
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
            if (Intersection2Triangles(triangles[i], triangles[j])) count++;
        }
    }
    std::cout << "\ncount = " << count << std::endl << std::endl;
    std::cout << "S1 = " << triangles[0].Square() << std::endl;
    std::cout << "S2 = " << triangles[0].test(Point(0, 0.9, 1.5)) << std::endl;
    std::cout << "One Plane " << TrianglesInOnePlanesIntersection(triangles[0], triangles[1]) << std::endl;
    std::cout << "Planes parallel " << PlaneParallel(triangles[0].GetPlane(), triangles[1].GetPlane()) << std::endl;
    std::cout << "plane equal " << PlaneEqual(triangles[0].GetPlane(), triangles[1].GetPlane()) << std::endl;
    triangles[0].GetPlane().Print();
    triangles[1].GetPlane().Print();
    Vector product = VectorProduct(Vector(1, 2, 3), Vector(4, 5, 6));
    std::cout << "vector product " << product.GetX() << " " << product.GetY() << " " << product.GetZ() << std::endl;
    std::cout << "planes normals 1, 2: " << triangles[0].GetPlane().GetVector().GetX() << " " << triangles[0].GetPlane().GetVector().GetY() << " " <<
                                            triangles[0].GetPlane().GetVector().GetZ() << " || " << 
                                            triangles[1].GetPlane().GetVector().GetX() << " " << triangles[1].GetPlane().GetVector().GetY() << " " <<
                                            triangles[1].GetPlane().GetVector().GetZ() <<std::endl;

    std::cout << "\ncut and line intersection test" << std::endl;
    Line line1(Point(0, 0, 0), Point(1 , 1, 0));
    printf("line\n");
    line1.GetDirectionVector().Print();
    line1.GetStartPoint().Print();
    printf("cut\n");
    Cut(Point(3,-1,0), Point(-1,1,0)).GetLine().GetDirectionVector().Print();
    Cut(Point(3,-1,0), Point(-1,1,0)).GetLine().GetStartPoint().Print();
    std::pair<bool, double> res1 = CutAndLineIntersection(Cut(Point(3, -1, 0), Point(-1, 1, 0)), line1);
    std::cout << "result: " << res1.first <<  " == " << res1.second << std::endl;


}


/*
2    
0 1 1
0 1 2
0 0 0 
0 0.9 1.5      
0 1 1
0 2 4

count = 1
*/

/*
2    
0 10 10
0 10 20
0 30 30 
0 0.9 1.5      
0 1 1
0 2 4

count = 0
*/

/*
2
0 0 2
0 2 0
2 0 0
0 3 3
0 5 5
0 3 5

count = 0
*/


// ERROR <= 3 meth
/*
2
0 0 2
0 2 0
2 0 0
0 0 2
0 2 0
0 0 0

count = 1
*/

// ERROR <= 3 meth
/*
2
0 0 2
0 2 0
2 0 0
0 1 0
0 -1 0
2 0 0

count = 1
*/

/*
2
0 0 2
0 2 0
0 0 0
1 0 2
1 2 0
1 0 0

count = 1
*/