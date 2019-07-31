/*
MatrixTest.cpp
*/

#include "JL/matrix/Matrix.h"
#include "JL/matrix/RandomMatrix.h"

#include <iostream>

using namespace jl;

void TestMatrix()
{
    std::cout << "##### Matrix Test #####\n";

    using T = int32_t;
    const T min = -10;
    const T max = 10;
    
    uniform_dist<T> rnInt32(min, max);
    auto reng = GetRandomEngine();

    // Addition
    {
        std::cout << "Test 1: Addition test\n";

        const size_t N = 3;
        const size_t M = 3;

        for (size_t i = 0; i < 1000; ++i)
        {
            auto A1 = RandomMatrix<T, N, M>(reng, min, max);
            auto A2 = RandomMatrix<T, N, M>(reng, min, max);

            auto A3 = A1 + A2;
            A1 += A2;
            ALWAYS_ASSERT(A1 == A3);

            A3 = A2 - A1;
            A2 -= A1;
            ALWAYS_ASSERT(A2 == A3);
        }
    }

    // Scalar multiplication
    {
        std::cout << "Test 2: Scalar multiplication test\n";

        const size_t N = 3;
        const size_t M = 3;

        for (size_t i = 0; i < 1000; ++i)
        {
            auto A1 = RandomMatrix<T, N, M>(reng, min, max);

            T s = rnInt32(reng);
            if (s == 0) ++s;

            auto A2 = s * A1;
            A1 *= s;
            ALWAYS_ASSERT(A1 == A2);

            A2 = A2 / s;
            A1 /= s;
            ALWAYS_ASSERT(A1 == A2);
        }
    }

    // Transposition
    {
        std::cout << "Test 3: Transposition test\n";

        const size_t N = 3;
        const size_t M = 2;

        for (size_t i = 0; i < 1000; ++i)
        {
            auto A1 = RandomMatrix<T, N, M>(reng, min, max);
            auto A2 = Transpose(A1);
            auto A3 = Transpose(A2);

            ALWAYS_ASSERT(A1.NumColumns() == A2.NumRows());
            ALWAYS_ASSERT(A1.NumRows() == A2.NumColumns());
            ALWAYS_ASSERT(A1 == A3);

        }
    }

    // Matrix multiplication
    {
        //std::cout << "Test 4: Matrix multiplication test\n";

        //const size_t N = 3;
        //const size_t M = 3;

        //for (size_t i = 0; i < 1000000; ++i)
        //{

        //}
    }
}