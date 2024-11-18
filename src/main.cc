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
    //std::cerr << N << "\n";
    for (int i = 0; i < N; i++){

        std::cin >> x >> y >> z;
        //std::cerr << x << y << z << "\n";
        Point point1(x, y, z);
        size = MaxSize(point1, size);

        std::cin >> x >> y >> z;
        //std::cerr << x << y << z << "\n";
        Point point2(x, y, z);
        size = MaxSize(point2, size);

        std::cin >> x >> y >> z;
        //std::cerr << x << y << z << "\n";
        Point point3(x, y, z);
        size = MaxSize(point3, size);

        Triangle triangle(point1, point2, point3);
        triangle.number = i;

        triangles.push_back(triangle);

        //std::cerr << "we are here\n";
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
    /*
    std::cout << "\ncount = " << counter << std::endl;
    
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
            if (Intersection2Triangles(triangles[i], triangles[j]))
            {
                FlagArray[triangles[i].number] = 1;
                FlagArray[triangles[j].number] = 1;
            };
        }
    }
    
    for (size_t i = 0; i < N; i++)
    {
        if(intersections[i])
            std::cout << i << std::endl;
    }
    */

    return 0;
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
v1
2
0 0 2
0 2 0
2 0 0
0 1 0
0 -1 0
2 0 0

count = 1
*/

// ERROR <= 3 meth
/*
v2
2
0 0 2
0 2 0
2 0 0
0 1 0
0 -1 0
1 1 0

count = 1
*/

// ERROR <= 3 meth
/*
v3
2
0 0 2
0 2 0
2 0 0
0 -1 0
0 3 0
3 0 0

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

count = 0
*/