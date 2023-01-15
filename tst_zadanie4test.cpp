
#include "Point.h"
#include "Straight.h"
#include "plane.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "math.h"


using namespace testing;


// 1.TESTY POZYWTYWNE
// PUNKT

TEST(Point, TestCreatingPoint)
{

    Point<double> point(10.0, 2.0, 3.0);

    EXPECT_EQ(point.x(), 10.0);
    EXPECT_EQ(point.y(), 2.0);
    EXPECT_EQ(point.z(), 3.0);

}


TEST(Point, TestDistance)
{

    Point<double> point1(10.0, 2.0, 3.0);
    Point<double> point2(30.0, 20.0, 10.0);


    EXPECT_EQ(sqrt(773), point1.distance(point2));
}


// PROSTA

TEST(Straight, TestStraightCreate)
{

    Straight<double> straight(10.0, 2.0, 3.0, 5.0, 5.0, 5.0);


    EXPECT_EQ(straight.px(), 10.0);
    EXPECT_EQ(straight.py(), 2.0);
    EXPECT_EQ(straight.pz(), 3.0);
    EXPECT_EQ(straight.vx(), 5.0);
    EXPECT_EQ(straight.vy(), 5.0);
    EXPECT_EQ(straight.vz(), 5.0);
}


TEST(Straight, TestStraightFromTwoPoints) {

    Point<double> point1(3.0, 2.0, 10.0);
    Point<double> point2(30.0, 30.0, 30.0);


    Straight<double> straight(point1, point2);


    EXPECT_EQ(straight.px(), 3.0);
    EXPECT_EQ(straight.py(), 2.0);
    EXPECT_EQ(straight.pz(), 10.0);
    EXPECT_EQ(straight.vx(), 30.0);
    EXPECT_EQ(straight.vy(), 30.0);
    EXPECT_EQ(straight.vz(), 30.0);
}

TEST(Straight, TestStraightFromPointAndVector) {

    Point<double> point1(90.0, 10.0, 3.0);
    Vector<double> vector1(4.0, 5.0, 6.0);

    Straight<double> straight(point1, vector1);



    EXPECT_EQ(straight.px(), 90.0);
    EXPECT_EQ(straight.py(), 10.0);
    EXPECT_EQ(straight.pz(), 3.0);
    EXPECT_EQ(straight.vx(), 4.0);
    EXPECT_EQ(straight.vy(), 5.0);
    EXPECT_EQ(straight.vz(), 6.0);
}


TEST(Vector, TestVectorCreate) {

    Vector<double> vector(3,4,2);

    EXPECT_EQ(vector.x(), 3);
    EXPECT_EQ(vector.y(), 4);
    EXPECT_EQ(vector.z(), 2);

}


TEST(Vector, TestVectorCreateTwoPoints) {

    Point<double> point1(90.0, 10.0, 3.0);
    Point<double> point2(30.0, 20.0, 10.0);

    Vector<double> vector(point1, point2);

    EXPECT_EQ(vector.x(), -60.00);
    EXPECT_EQ(vector.y(), 10.0);
    EXPECT_EQ(vector.z(), 7.0);
}


// Blad
TEST(Vector, TestVectorCreateFromStraight) {

    // Blad
    // W istniejącej implementacji nie można zaincludować Straight do Vector,z powodu pętli wstrzykiwania zależności

//    Straight<double> straight(10.0, 2.0, 3.0, 5.0, 5.0, 5.0);

//    Vector<double> vector(straight);

//    EXPECT_EQ(vector.x(), -5.00);
//    EXPECT_EQ(vector.y(), 3.0);
//    EXPECT_EQ(vector.z(), 2.0);
}

TEST(Vector, TestVectorAdd) {

    Point<double> point1(90.0, 10.0, 3.0);
    Point<double> point2(30.0, 20.0, 10.0);

    Vector<double> vector1(point1, point2);


    Point<double> point3(1.0, 1.0, 1.0);
    Point<double> point4(70.0, 70.0, 10.0);

    Vector<double> vector2(point3, point4);

    Vector<double> vector3 = vector2.add(vector1, vector2);

        EXPECT_EQ(vector3.x(), 9.00);
        EXPECT_EQ(vector3.y(), 79.0);
        EXPECT_EQ(vector3.z(), 16.0);


}



TEST(Vector, TestVectorSubtract) {

    Point<double> point1(90.0, 10.0, 3.0);
    Point<double> point2(30.0, 20.0, 10.0);

    Vector<double> vector1(point1, point2);


    Point<double> point3(1.0, 1.0, 1.0);
    Point<double> point4(70.0, 70.0, 10.0);

    Vector<double> vector2(point3, point4);

    Vector<double> vector3 = vector2.subtract(vector1, vector2);

        EXPECT_EQ(vector3.x(), -129.00);
        EXPECT_EQ(vector3.y(), -59.0);
        EXPECT_EQ(vector3.z(), -2.0);


}



TEST(Vector, TestVectorMultiply) {

    Point<double> point1(90.0, 10.0, 3.0);
    Point<double> point2(30.0, 20.0, 10.0);

    Vector<double> vector1(point1, point2);


    Point<double> point3(1.0, 1.0, 1.0);
    Point<double> point4(70.0, 70.0, 10.0);

    Vector<double> vector2(point3, point4);

    Vector<double> vector3 = vector2.crossMultiply(vector1, vector2);

        EXPECT_EQ(vector3.x(), -393.00);
        EXPECT_EQ(vector3.y(), 1023.0);
        EXPECT_EQ(vector3.z(), -4830.0);


}

// Testy plaszczyzny

TEST(Plane, TestPlaneCreation) {

    Plane plane(1,5,4,7,6,7,10);


    EXPECT_EQ(plane.getX0(), 1);
    EXPECT_EQ(plane.getY0(), 5);
    EXPECT_EQ(plane.getZ0(), 4);
    EXPECT_EQ(plane.getX1(), 7);
    EXPECT_EQ(plane.getY1(), 6);
    EXPECT_EQ(plane.getZ1(), 7);
    EXPECT_EQ(plane.getLength(), 10);
}




TEST(Plane, TestPlaneVectorPoint) {


    Point<double> point1(90.0, 10.0, 3.0);
    Point<double> point2(30.0, 20.0, 10.0);

    Vector<double> vector1(point1, point2);


    Point<double> point3(1.0, 1.0, 1.0);

    Plane plane(point3, vector1);


    EXPECT_EQ(plane.getX0(), 1);
    EXPECT_EQ(plane.getY0(), 1);
    EXPECT_EQ(plane.getZ0(), 1);
    EXPECT_EQ(plane.getX1(), -60);
    EXPECT_EQ(plane.getY1(), 10);
    EXPECT_EQ(plane.getZ1(), 7);
}



// 2.Testy negatywne
TEST(PointNegative, TestCreatingPoint)
{

    Point<double> point(10.0, 2.0, 3.0);

    EXPECT_EQ(point.x(), 30.0);
    EXPECT_EQ(point.y(), 32.0);
    EXPECT_EQ(point.z(), 43.0);

}


TEST(PointNegative, TestDistance)
{

    Point<double> point1(10.0, 2.0, 3.0);
    Point<double> point2(30.0, 20.0, 10.0);


    EXPECT_EQ(sqrt(770), point1.distance(point2));
}


TEST(StraightNegative, TestStraightCreate)
{

    Straight<double> straight(10.0, 2.0, 3.0, 5.0, 5.0, 5.0);


    EXPECT_EQ(straight.px(), 10.0);
    EXPECT_EQ(straight.py(), 23.0);
    EXPECT_EQ(straight.pz(), 33.0);
    EXPECT_EQ(straight.vx(), 353.0);
    EXPECT_EQ(straight.vy(), 35.0);
    EXPECT_EQ(straight.vz(), 35.0);
}


TEST(StraightNegative, TestStraightFromTwoPoints) {


    Point<double> point1(90.0, 10.0, 3.0);
    Point<double> point2(30.0, 20.0, 10.0);


    Straight<double> straight(point1, point2);


    EXPECT_EQ(straight.px(), 930.0);
    EXPECT_EQ(straight.py(), 310.0);
    EXPECT_EQ(straight.pz(), 33.0);
    EXPECT_EQ(straight.vx(), 330.0);
    EXPECT_EQ(straight.vy(), 230.0);
    EXPECT_EQ(straight.vz(), 130.0);
}

TEST(StraightNegative, TestStraightFromPointAndVector) {

    Point<double> point1(90.0, 10.0, 3.0);
    Vector<double> vector1(4.0, 5.0, 6.0);

    Straight<double> straight(point1, vector1);

    EXPECT_EQ(straight.px(), 940.0);
    EXPECT_EQ(straight.py(), 130.0);
    EXPECT_EQ(straight.pz(), 33.0);
    EXPECT_EQ(straight.vx(), 44.0);
    EXPECT_EQ(straight.vy(), 45.0);
    EXPECT_EQ(straight.vz(), 64.0);
}
