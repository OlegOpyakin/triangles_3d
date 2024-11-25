#include "parsing_triangles.hpp"
#include <vector>
#include <iostream>

int main(){
    const int max = 1000000;
    int N = 0;
    double x, y, z;
    std::list<Triangle> triangles;
    int count = 0;

    double size = 0;

    std::cin >> N;
    for (int i = 0; i < N; i++){

        std::cin >> x >> y >> z;
        Point point1(x, y, z);
        size = MaxSize(point1, size);

        std::cin >> x >> y >> z;
        Point point2(x, y, z);
        size = MaxSize(point2, size);

        std::cin >> x >> y >> z;
        Point point3(x, y, z);
        size = MaxSize(point3, size);

        Triangle triangle(point1, point2, point3);
        triangle.number = i;

        triangles.push_back(triangle);
    }

    bool *intersections = new bool[N];
    
    std::list<Triangle> intersected_triangles;
    int counter = 0;
    
    OctTree tree(triangles, size);
    
    ParseNode(intersections, tree.root_);

    for (size_t i = 0; i < N; i++)
    {
        if(intersections[i])
            std::cout << i << std::endl;
    }
    
    delete[] intersections;
   return 0;
}