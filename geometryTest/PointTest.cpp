/*
PointTest.cpp
*/

#include "geometry/Random.h"
#include "geometry/Point.h"

#include <iostream>
#include <cassert>

using namespace geom;

void TestPoint()
{
    // Arithmetic operation test
    {
        std::cout << "Test 1: Arithmetic operation test\n";

        auto reng = geom::GetRandomEngine();

        for (size_t i = 0; i < 100000; ++i)
        {
            auto p1 = geom::RandomPoint<double, 3>(reng, 0, 1);
            auto p2 = geom::RandomPoint<double, 3>(reng, 0, 1);

            auto p3 = p1 + p2;
            p1 += p2;
            assert(p3 == p1);

            p3 = p2 - p1;
            p2 -= p1;
            assert(p3 == p2);

            double scalar = std::rand() % 10 + 1;

            p3 = scalar * p1;
            p1 *= scalar;
            assert(p1 == p3);

            p3 = p3 / scalar;
            p1 /= scalar;
            assert(p1 == p3);
        }
    }
}