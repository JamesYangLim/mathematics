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
    using T = int32_t;
    auto reng = jl::GetRandomEngine();

    // Arithmetic operation test
    {
        std::cout << "Test 1: Arithmetic operation test\n";

        const size_t D = 3;
        const T min = -10;
        const T max = 10;
        jl::uniform_dist<T> rn(min, max);
        
        for (size_t i = 0; i < 100000; ++i)
        {
            auto a = jl::RandomPoint<T, D>(reng, min, max);
            auto b = jl::RandomPoint<T, D>(reng, min, max);

            auto c = a + b;
            a += b;
            ALWAYS_ASSERT(c == a);

            c = b - a;
            b -= a;
            ALWAYS_ASSERT(c == b);

            T s = rn(reng);
            if (s == 0) ++s;

            c = s * a;
            a *= s;
            ALWAYS_ASSERT(a == c);

            c = c / s;
            a /= s;
            ALWAYS_ASSERT(a == c);
        }
    }

    // Dot product test
    {
        std::cout << "Test 2: Dot product test\n";

        const size_t D = 3;
        const T min = -10;
        const T max = 10;
        jl::uniform_dist<T> rn(min, max);

        for (size_t i = 0; i < 1000; ++i)
        {
            auto a = jl::RandomPoint<T, D>(reng, min, max);
            auto b = jl::RandomPoint<T, D>(reng, min, max);
            auto c = jl::RandomPoint<T, D>(reng, min, max);

            {
                T s = jl::DotProduct(a, a);
                T mSqd = jl::MagnitudeSquare(a);
                ALWAYS_ASSERT(s == mSqd);
            }

            {
                // Commutative
                T s1 = jl::DotProduct(a, b);
                T s2 = jl::DotProduct(b, a);
                ALWAYS_ASSERT(s1 == s2);
                
                // Distributive
                s1 = jl::DotProduct(a, (b + c));
                s2 = jl::DotProduct(a, b) + jl::DotProduct(a, c);
                ALWAYS_ASSERT(s1 == s2);

                T s = rn(reng);
                if (s == 0) ++s;

                // Bilinear
                s1 = jl::DotProduct(a, (s * b + c));
                s2 = s * jl::DotProduct(a, b) + jl::DotProduct(a, c);
                ALWAYS_ASSERT(s1 == s2);

                // Associative law for scalar and dot product
                s1 = s * jl::DotProduct(a, b);
                s2 = jl::DotProduct((s * a), b);
                ALWAYS_ASSERT(s1 == s2);
                s2 = jl::DotProduct(a, (s * b));
                ALWAYS_ASSERT(s1 == s2);
            }
        }
    }

    // Cross product
    {
        std::cout << "Test 3: Cross product test\n";

        using T = float;
        const size_t D = 3;
        const T min = -10;
        const T max = 10;
        jl::uniform_dist<T> rn(min, max);

        for (size_t i = 0; i < 1000000; ++i)
        {
            auto a = jl::RandomPoint<T, D>(reng, min, max);
            auto b = jl::RandomPoint<T, D>(reng, min, max);

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