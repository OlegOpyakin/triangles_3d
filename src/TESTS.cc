#include <gtest/gtest.h>
#include "func.hpp"
#include <random>
#include <ctime>

class PerfectTest : public ::testing::Test{
protected:
/*
    PerfectCache* cache;
    PerfectCache* cache1;
    PerfectCache* cache2;
    PerfectCache* cache3;

    void SetUp() override {
        cache = new PerfectCache(3);
        cache1 = new PerfectCache(1);
        cache2= new PerfectCache(2);
        cache3 = new PerfectCache(1000);
    }

    void TearDown() override {
        delete cache;
        delete cache1;
        delete cache2;
        delete cache3;
    }
    */
};

class VectorTest : public ::testing::Test{
protected:

    Vector* v1;
    Vector* v2;

    Point* p11;
    Point* p12;
    Point* p21;
    Point* p22;

    void SetUp() override {
        p11 = new Point();
        p12 = new Point();
        p21 = new Point();
        p22 = new Point();
        v1 = new Vector();
        v2 = new Vector();
    }

    void TearDown() override {
        delete p11;
        delete p12;
        delete p21;
        delete p22;
        delete v1;
        delete v2;
    }
};

class PlaneTest : public ::testing::Test{
protected:

    Point* p11;
    Point* p12;
    Point* p13;
    Point* p21;
    Point* p22;
    Point* p23;
    Point* p31;
    Point* p32;
    Point* p33;

    Plane* plane1;
    Plane* plane2;
    Plane* plane3;

    void SetUp() override {
        p11 = new Point(0, 0, 0);
        p12 = new Point(0, 1, 0);
        p13 = new Point(1, 0, 0);

        p21 = new Point(0, 0, 1);
        p22 = new Point(0, 1, 1);
        p23 = new Point(1, 0, 1);
        
        p31 = new Point(0, 0, 2);
        p32 = new Point(2, 0, 0);
        p33 = new Point(0, 2, 0);

        plane1 = new Plane(*p11, *p12, *p13);
        plane2 = new Plane(*p21, *p22, *p23);
        plane3 = new Plane(*p31, *p32, *p33);
    }

    void TearDown() override {
        delete p11;
        delete p12;
        delete p13;
        delete p21;
        delete p22;
        delete p23;
        delete p31;
        delete p32;
        delete p33;
        delete plane1;
        delete plane2;
        delete plane3;
    }
};

class TriangleTest : public ::testing::Test{
protected:

    Point* p11;
    Point* p12;
    Point* p13;
    Point* p21;
    Point* p22;
    Point* p23;
    Point* p31;
    Point* p32;
    Point* p33;
    Point* point_in_triangle1;
    Point* point_outside_triangle1;
    Point* plane_point1;
    Point* plane_point2;
    Point* plane_point3;

    Triangle* triangle1;
    Triangle* triangle2;
    Triangle* triangle3;

    Plane* plane;

    Line* line1;
    Line* line2;

    void SetUp() override {
        p11 = new Point(0, 0, 0);
        p12 = new Point(0, 3, 0);
        p13 = new Point(4, 0, 0);

        p21 = new Point(0, 0, 0);
        p22 = new Point(1, 2, 0);
        p23 = new Point(4, 1, 0);
        
        p31 = new Point(5, 0, 0);
        p32 = new Point(5, 5, 0);
        p33 = new Point(7, 4, 0);
        
        plane_point1 = new Point(2, -1, 0);
        plane_point2 = new Point(2, 1, 0);
        plane_point3 = new Point(2, 1, 1);

        point_in_triangle1 = new Point(1, 1, 0);
        point_outside_triangle1 = new Point(3, 4, 0);

        triangle1 = new Triangle(*p11, *p12, *p13);
        triangle2 = new Triangle(*p21, *p22, *p23);
        triangle3 = new Triangle(*p31, *p32, *p33);

        line1 = new Line(*p31, *p32);
        line2 = new Line(*p21, *p23);

        plane = new Plane(*plane_point1, *plane_point2, *plane_point3);
    }

    void TearDown() override {
        delete p11;
        delete p12;
        delete p13;
        delete p21;
        delete p22;
        delete p23;
        delete p31;
        delete p32;
        delete p33;
        delete plane_point1;
        delete plane_point2;
        delete plane_point3;
        delete point_in_triangle1;
        delete point_outside_triangle1;
        delete triangle1;
        delete triangle2;
        delete triangle3; 
        delete plane;
    }
};

class CutAndLineTest : public ::testing::Test{
protected:

    Point* p11;
    Point* p12;
    Point* p21;
    Point* p22;
    Point* p31;
    Point* p32;
    Point* p41;
    Point* p42;

    Line* line1;
    Line* line2;
    Line* line3;
    Line* line4;

    Cut* cut1;

    void SetUp() override {
        p11 = new Point(0, 0, 0);
        p12 = new Point(0, 1, 0);

        // l2 // l1
        p21 = new Point(1, 0, 0);
        p22 = new Point(1, 1, 0);
        
        // l3 ^ l1, but l3 !^ c1
        p31 = new Point(5, 0, 0);
        p32 = new Point(5, 5, 0);

        // l4 ^ l1 and l4 ^ c1
        p41 = new Point(1, 1, 0);
        p42 = new Point(0, 1, 0);
        
        line1 = new Line(*p11, *p12);
        line2 = new Line(*p21, *p22);
        line3 = new Line(*p31, *p32);
        line4 = new Line(*p41, *p42);

        cut1 = new Cut(*p12, *p11);
    }

    void TearDown() override {
        delete p11;
        delete p12;
        delete p21;
        delete p22;
        delete p31;
        delete p32;
        delete p41;
        delete p42;
        delete line1;
        delete line2;
        delete line3;
        delete line4;
        delete cut1;
    }
};


class PointPoint : public ::testing::Test{
protected:
    Triangle* test_1_a;
    Triangle* test_1_b;

    Triangle* test_2_a;
    Triangle* test_2_b;

    void SetUp() override {
        // true
        test_1_a = new Triangle(Point(0, 0, 0), Point(0, 0, 0), Point(0, 0, 0));
        test_1_b = new Triangle(Point(0, 0, 0), Point(0, 0, 0), Point(0, 0, 0));
        // false    //ERROR (WHY)
        test_2_a = new Triangle(Point(0, 0, 0), Point(0, 0, 0), Point(0, 0, 0)); 
        test_2_b = new Triangle(Point(1, 1, 1), Point(1, 1, 1), Point(1, 1, 1));
    }
    void TearDown() override {
        delete test_1_a;
        delete test_1_b;

        delete test_2_a;
        delete test_2_b;
    }
};

class CutCut : public ::testing::Test{
protected:
    Triangle* test_3_a;
    Triangle* test_3_b;

    Triangle* test_4_a;
    Triangle* test_4_b;

    Triangle* test_5_a;
    Triangle* test_5_b;

    Triangle* test_6_a;
    Triangle* test_6_b;

    void SetUp() override {
        // parallel cut cut
        // true
        test_3_a = new Triangle(Point(0, 0, 0), Point(1, 0, 0), Point(-1, 0, 0));
        test_3_b = new Triangle(Point(0, 0, 0), Point(2, 0, 0), Point(-2, 0, 0));
        // false
        test_4_a = new Triangle(Point(0, 0, 0), Point(1, 0, 0), Point(-1, 0, 0));
        test_4_b = new Triangle(Point(0, 0, 1), Point(2, 0, 1), Point(-2, 0, 1));

        // not parallel cut cut
        // true
        test_5_a = new Triangle(Point(0, 0, 0), Point(1, 0, 0), Point(-1, 0, 0));
        test_5_b = new Triangle(Point(0, 0, 0), Point(0, 1, 0), Point(0, -1, 0));
        // false
        test_6_a = new Triangle(Point(0, 0, 0), Point(1, 0, 0), Point(-1, 0, 0));
        test_6_b = new Triangle(Point(0, 0, 1), Point(0, 1, 1), Point(0, -1, 1));
    }

    void TearDown() override {
        delete test_3_a;
        delete test_3_b;

        delete test_4_a;
        delete test_4_b;

        delete test_5_a;
        delete test_5_b;

        delete test_6_a;
        delete test_6_b;
    }
};    

class PointCut : public ::testing::Test{
protected:
    Triangle* test_7_a;
    Triangle* test_7_b;

    void SetUp() override {
        // true
        test_7_a = new Triangle(Point(0, 0, 0), Point(0, 0, 0), Point(0, 0, 0));
        test_7_b = new Triangle(Point(-1, 0, 0), Point(1, 0, 0), Point(0, 0, 0));
    }
    void TearDown() override {
        delete test_7_a;
        delete test_7_b;

    }
};

class PointTriangle : public ::testing::Test{
protected:
    Triangle* test_8_a;
    Triangle* test_8_b;

    void SetUp() override {
        // true
        test_8_a = new Triangle(Point(1, 1, 0), Point(1, 1, 0), Point(1, 1, 0));
        test_8_b = new Triangle(Point(3, 0, 0), Point(0, 4, 0), Point(0, 0, 0));

    }
    void TearDown() override {
        delete test_8_a;
        delete test_8_b;

    }
};

class CutTriangle : public ::testing::Test{
protected:

    Triangle* test_9_a;
    Triangle* test_9_b;

    Triangle* test_10_a;
    Triangle* test_10_b;

    void SetUp() override {  
        // cut and triangle
        // false
        test_9_a = new Triangle(Point(1, -10, 1), Point(1, 10, 1), Point(1, 0, 1));
        test_9_b = new Triangle(Point(3, 0, 0), Point(0, 4, 0), Point(0, 0, 0));
        
        // cut and triangle (hard)  
        // false
        test_10_a = new Triangle(Point(1, -1, 1), Point(1, 1, 1), Point(1, -1, 1));
        test_10_b = new Triangle(Point(3, 0, 0), Point(0, 4, 0), Point(0, 0, 0));
    }
    void TearDown() override {


        delete test_9_a;
        delete test_9_b;

        delete test_10_a;
        delete test_10_b;
    }
};

class Triangles : public ::testing::Test{
protected:
    Triangle* test_11_a;
    Triangle* test_11_b;

    Triangle* test_12_a;
    Triangle* test_12_b;

    Triangle* test_13_a;
    Triangle* test_13_b;

    Triangle* test_14_a;
    Triangle* test_14_b;

    Triangle* test_15_a;
    Triangle* test_15_b;

    Triangle* test_16_a;
    Triangle* test_16_b;

    Triangle* test_17_a;
    Triangle* test_17_b;


    void SetUp() override {  
        // true
        test_11_a = new Triangle(Point(0, 1, 1), Point(0, 1, 2), Point(0, 0, 0));
        test_11_b = new Triangle(Point(0, 2, 4), Point(0, 1, 1), Point(0, 0.9, 1.5));

        // false
        test_12_a = new Triangle(Point(0, 10, 10), Point(0, 10, 20), Point(0, 30, 30));
        test_12_b = new Triangle(Point(0, 2, 4), Point(0, 1, 1), Point(0, 0.9, 1.5));

        // false
        test_13_a = new Triangle(Point(0, 0, 2), Point(0, 2, 0), Point(2, 0, 0));
        test_13_b = new Triangle(Point(0, 3, 3), Point(0, 5, 5), Point(0, 3, 5));

        // true
        test_14_a = new Triangle(Point(0, 0, 2), Point(0, 2, 0), Point(2, 0, 0));
        test_14_b = new Triangle(Point(0, 1, 0), Point(0, -1, 0), Point(2, 0, 0));

        // true
        test_15_a = new Triangle(Point(0, 0, 2), Point(0, 2, 0), Point(2, 0, 0));
        test_15_b = new Triangle(Point(0, 1, 0), Point(0, -1, 0), Point(1, 1, 0));

        // true
        test_16_a = new Triangle(Point(0, 0, 2), Point(0, 2, 0), Point(2, 0, 0));
        test_16_b = new Triangle(Point(0, -1, 0), Point(3, 0, 0), Point(0, 3, 0));

        // false
        test_17_a = new Triangle(Point(0, 0, 2), Point(0, 2, 0), Point(0, 0, 0));
        test_17_b = new Triangle(Point(1, 0, 2), Point(1, 2, 0), Point(1, 0, 0));


    }
    
    void TearDown() override {
        delete test_11_a;
        delete test_11_b;

        delete test_12_a;
        delete test_12_b;

        delete test_13_a;
        delete test_13_b;

        delete test_14_a;
        delete test_14_b;

        delete test_15_a;
        delete test_15_b;

        delete test_16_a;
        delete test_16_b;

        delete test_17_a;
        delete test_17_b;
    }
};


// ---------------------- Test for Vector Product ----------------------

TEST_F(VectorTest, VectorProduct) {
    v1->SetX(0);
    v1->SetY(-5);
    v1->SetZ(5);

    v2->SetX(-3);
    v2->SetY(2);
    v2->SetZ(2);
    
    EXPECT_EQ(VectorProduct(*v1, *v2).GetX(), -20);
    EXPECT_EQ(VectorProduct(*v1, *v2).GetY(), -15);
    EXPECT_EQ(VectorProduct(*v1, *v2).GetZ(), -15);
}

// ---------------------- Tests for Vector Colliniar ---------------------

TEST_F(VectorTest, VectorColliniarFalse) {
    v1->SetX(0);
    v1->SetY(-5);
    v1->SetZ(5);

    v2->SetX(-3);
    v2->SetY(2);
    v2->SetZ(2);

    EXPECT_FALSE(VectorColliniar(*v1, *v2));
}


TEST_F(VectorTest, VectorColliniarTrue) {
    v1->SetX(0);
    v1->SetY(-5);
    v1->SetZ(5);

    v2->SetX(0);
    v2->SetY(-2);
    v2->SetZ(2);

    EXPECT_TRUE(VectorColliniar(*v1, *v2));
}


// -------------------- Tests for Plane Parallel --------------------

TEST_F(PlaneTest, PlaneParallel) {
    EXPECT_FALSE(PlaneParallel(*plane1, *plane3));
    EXPECT_FALSE(PlaneParallel(*plane2, *plane3));
    EXPECT_TRUE(PlaneParallel(*plane1, *plane2));
}


// --------------------- Tests for Plane Equal ----------------------

TEST_F(PlaneTest, PlaneParallelFalse) {
    EXPECT_FALSE(PlaneEqual(*plane1, *plane2));
    EXPECT_FALSE(PlaneEqual(*plane1, *plane3));
    EXPECT_FALSE(PlaneEqual(*plane2, *plane3));
    EXPECT_TRUE(PlaneEqual(*plane1, *plane1));
    EXPECT_TRUE(PlaneEqual(*plane2, *plane2));
    EXPECT_TRUE(PlaneEqual(*plane3, *plane3));

}

// ------------------ Test for Plane Intersection ------------------- 

TEST_F(PlaneTest, VectorPlaneIntersection) {
    EXPECT_EQ(VectorPlanesIntersection(*plane1, *plane3).GetX(), 4);
    EXPECT_EQ(VectorPlanesIntersection(*plane1, *plane3).GetY(), -4);
    EXPECT_EQ(VectorPlanesIntersection(*plane1, *plane3).GetZ(), 0);
}

TEST_F(PlaneTest, PointPlanesIntersection) {
    EXPECT_EQ(PointPlanesIntersection(*plane1, *plane3).GetX(), 0);
    EXPECT_EQ(PointPlanesIntersection(*plane1, *plane3).GetY(), 2);
    EXPECT_EQ(PointPlanesIntersection(*plane1, *plane3).GetZ(), 0);

}

// -------- Tests for Triangles in One Plane Intersection ----------- 

TEST_F(TriangleTest, PointInTriangle) {
    EXPECT_FALSE(triangle1->PointInTriangle(*point_outside_triangle1));
    // Check S1 and S2 equal
    EXPECT_TRUE(triangle1->PointInTriangle(*point_in_triangle1));
}

TEST_F(TriangleTest, TrianglesInOnePlanesIntersection) {
    EXPECT_TRUE(TrianglesInOnePlanesIntersection(*triangle1, *triangle2));
    EXPECT_FALSE(TrianglesInOnePlanesIntersection(*triangle1, *triangle3));
}

TEST_F(TriangleTest, AllPointRightOfPlane){
    EXPECT_TRUE(triangle3->AllPointsRightOfPlane(*plane));
    EXPECT_FALSE(triangle1->AllPointsRightOfPlane(*plane));
}

// ----------- Tests for Cut and Line Intersection ------------- 

TEST_F(CutAndLineTest, LinesParallel) {
    EXPECT_TRUE(LinesParallelCheck(*line1, *line2));
    EXPECT_FALSE(LinesParallelCheck(*line1, *line3));
}

TEST_F(CutAndLineTest, CutAndLineIntersection) {
    EXPECT_FALSE(CutAndLineIntersection(*cut1, *line2).first);
    EXPECT_FALSE(CutAndLineIntersection(*cut1, *line3).first);
    EXPECT_TRUE(CutAndLineIntersection(*cut1, *line4).first);
}

// --------- Tests for Triangle and Line Intersection ----------- 


TEST_F(TriangleTest, TriangleLineIntersection) {
    EXPECT_FALSE(triangle1->TriangleLineIntersection(*line1).first);
    EXPECT_TRUE(triangle1->TriangleLineIntersection(*line2).first);
}

// ------------ Tests for Triangles Intersecrions ---------------

TEST_F(PointPoint, PointPointIntersection) {
    EXPECT_TRUE(Intersection2Triangles(*test_1_a, *test_1_b));
    EXPECT_FALSE(Intersection2Triangles(*test_2_a, *test_2_b));
}

TEST_F(CutCut, CutCutIntersection) {
    EXPECT_TRUE(Intersection2Triangles(*test_3_a, *test_3_b));
    EXPECT_FALSE(Intersection2Triangles(*test_4_a, *test_4_b));
    EXPECT_TRUE(Intersection2Triangles(*test_5_a, *test_5_b));
    EXPECT_FALSE(Intersection2Triangles(*test_6_a, *test_6_b));
}

TEST_F(PointCut, PointCutIntersection) {
    EXPECT_TRUE(Intersection2Triangles(*test_7_a, *test_7_b));
}
TEST_F(PointTriangle, PointTriangleIntersection) {
    EXPECT_TRUE(Intersection2Triangles(*test_8_a, *test_8_b));
}

TEST_F(CutTriangle, CutTriangleIntersection) {
    EXPECT_FALSE(Intersection2Triangles(*test_9_a, *test_9_b));
    EXPECT_FALSE(Intersection2Triangles(*test_10_a, *test_10_b));
}



TEST_F(Triangles, TrianglesIntersections) {    
    EXPECT_TRUE(Intersection2Triangles(*test_11_a, *test_11_b));
    EXPECT_FALSE(Intersection2Triangles(*test_12_a, *test_12_b));
    EXPECT_FALSE(Intersection2Triangles(*test_13_a, *test_13_b));
    EXPECT_TRUE(Intersection2Triangles(*test_14_a, *test_14_b));
    EXPECT_TRUE(Intersection2Triangles(*test_15_a, *test_15_b));
    EXPECT_TRUE(Intersection2Triangles(*test_16_a, *test_16_b));
    EXPECT_FALSE(Intersection2Triangles(*test_17_a, *test_17_b));

    
}


// ------------------- Time for Million Elements test -------------------
/*
TEST_F(LFUTest, MillionElemsTimeTest) {
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<int> dist(1, 999); // distribute results between 1 and 6 inclusive.
    
    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        lfu3->Put(dist(gen));
    }
    clock_t end = clock();
    double seconds = ((double)(end - start))/CLOCKS_PER_SEC;
    ASSERT_TRUE(seconds <= 1.0);
}

TEST_F(PerfectTest, MillionElemsTimeTest) {
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<int> dist(1, 999); // distribute results between 1 and 6 inclusive.

    std::vector<int> mas;
    for (int i = 0; i < 1000000; i++) {
        mas.push_back(dist(gen));
    }
    cache3->FillMas(mas);

    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        cache3->Put();
    }
    clock_t end = clock();
    double seconds = ((double)(end - start))/CLOCKS_PER_SEC;
    ASSERT_TRUE(seconds <= 1.0);
}

*/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
