/*
PointTest.cpp
*/

#include "JL/geometry/Random.h"
#include "JL/geometry/Point.h"

#include <iostream>

# define PI 3.14159265358979323846

using namespace jl;

int32_t ToDegree(float radian)
{
    return std::round((radian * 180) / PI);
}

void TestPoint()
{
    std::cout << "##### Point Test #####\n";

    using T = int32_t;
    const size_t D = 3;
    const T min = -10;
    const T max = 10;

    uniform_dist<T> rnInt32(min, max);
    auto reng = GetRandomEngine();

    // Addition
    {
        std::cout << "Test 1: Addition test\n";

        for (size_t i = 0; i < 1000000; ++i)
        {
            auto a = RandomPoint<T, D>(reng, min, max);
            auto b = RandomPoint<T, D>(reng, min, max);

            auto c = a + b;
            a += b;
            ALWAYS_ASSERT(c == a);

            c = b - a;
            b -= a;
            ALWAYS_ASSERT(c == b);
        }
    }

    // Scalar multiplication
    {
        std::cout << "Test 2: Scalar multiplication test\n";

        for (size_t i = 0; i < 1000000; ++i)
        {
            auto a = RandomPoint<T, D>(reng, min, max);

            T s = rnInt32(reng);
            if (s == 0) ++s;

            auto c = s * a;
            a *= s;
            ALWAYS_ASSERT(a == c);

            c = c / s;
            a /= s;
            ALWAYS_ASSERT(a == c);
        }
    }

    // Dot product
    {
        std::cout << "Test 3: Dot product test\n";

        for (size_t i = 0; i < 1000000; ++i)
        {
            auto a = RandomPoint<T, D>(reng, min, max);
            auto b = RandomPoint<T, D>(reng, min, max);
            auto c = RandomPoint<T, D>(reng, min, max);

            T d = DotProduct(a, a);
            T mSqd = MagnitudeSquare(a);
            ALWAYS_ASSERT(d == mSqd);

            // Commutative
            T s1 = DotProduct(a, b);
            T s2 = DotProduct(b, a);
            ALWAYS_ASSERT(s1 == s2);

            // Distributive
            s1 = DotProduct(a, (b + c));
            s2 = DotProduct(a, b) + DotProduct(a, c);
            ALWAYS_ASSERT(s1 == s2);

            T s = rnInt32(reng);
            if (s == 0) ++s;

            // Bilinear
            s1 = DotProduct(a, (s * b + c));
            s2 = s * DotProduct(a, b) + DotProduct(a, c);
            ALWAYS_ASSERT(s1 == s2);

            // Associative law for scalar and dot product
            s1 = s * DotProduct(a, b);
            s2 = DotProduct((s * a), b);
            ALWAYS_ASSERT(s1 == s2);
            s2 = DotProduct(a, (s * b));
            ALWAYS_ASSERT(s1 == s2);
        }
    }

    // Cross product
    {
        std::cout << "Test 4: Cross product test\n";

        using T = float;

        for (size_t i = 0; i < 1000000; ++i)
        {
            auto a = RandomPoint<T, D>(reng, min, max);
            auto b = RandomPoint<T, D>(reng, min, max);

            // self cross product of a vector is the zero vector
            auto zero = Zero<T, D>();
            ALWAYS_ASSERT(CrossProduct(a, a) == zero);
            ALWAYS_ASSERT(CrossProduct(b, b) == zero);

            // anticommutative
            auto c = CrossProduct(a, b);
            auto d = CrossProduct(b, a);
            ALWAYS_ASSERT(c == -d);

            // a x b = c -> c is perpendicular to a & b
            int32_t angle1 = ToDegree(AngleBetween(a, c));
            int32_t angle2 = ToDegree(AngleBetween(b, c));
            ALWAYS_ASSERT(angle1 == 90);
            ALWAYS_ASSERT(angle2 == angle1);
        }
    }
}