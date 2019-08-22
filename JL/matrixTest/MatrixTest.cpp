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

    // Identity
    {
        MatrixSqd<T, 3> iA = IdentityMatrix<T, 3, 3>();
        std::cout << iA << "\n";
        //ALWAYS_ASSERT(iA == InverseMatrix(iA));
    }

    // Addition
    {
        std::cout << "Test 1: Addition test\n";

        const size_t M = 3;
        const size_t N = 3;

        for (size_t i = 0; i < 1000; ++i)
        {
            auto A1 = RandomMatrix<T, M, N>(reng, min, max);
            auto A2 = RandomMatrix<T, M, N>(reng, min, max);

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

        const size_t M = 3;
        const size_t N = 3;

        for (size_t i = 0; i < 1000; ++i)
        {
            auto A1 = RandomMatrix<T, M, N>(reng, min, max);

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

        /*
        1. T(T(A)) = A
        2. T(A + B) =  T(A) + T(B)
        3. T(AB) = T(B)T(A)
        4. T(cA) = cT(A)
        5. det(T(A)) = det(A)
        6. [a.b] = T(a)b
        7. If A has only real entries, then T(A)A is a positive-semidefinite matrix.
        8. Inv(T(A)) = T(Inv(A))
        9. If A is a square matrix, then its eigenvalues are equal to the eigenvalues of its transpose, since they share the same characteristic polynomial.
        */

        const size_t M = 2;
        const size_t N = 3;

        for (size_t i = 0; i < 1000; ++i)
        {
            auto A1 = RandomMatrix<T, M, N>(reng, min, max);
            auto A2 = Transpose(A1);
            auto A3 = Transpose(A2);

            ALWAYS_ASSERT(A1.NumColumns() == A2.NumRows());
            ALWAYS_ASSERT(A1.NumRows() == A2.NumColumns());
            ALWAYS_ASSERT(A1 == A3);
        }
    }

    // Matrix multiplication
    {
         std::cout << "Test 4: Matrix multiplication test\n";

         for (size_t i = 0; i < 1000; ++i)
         {
             {
                 const size_t M = 2, N = 3, P = 2;
                 auto A = RandomMatrix<T, M, N>(reng, min, max);
                 auto B = RandomMatrix<T, N, P>(reng, min, max);
                 auto C = A * B;
                 ALWAYS_ASSERT(C.NumRows() == M);
                 ALWAYS_ASSERT(C.NumColumns() == P);
             }
             {
                 const size_t M = 2, N = 3, P = 4;
                 auto A = RandomMatrix<T, M, N>(reng, min, max);
                 auto B = RandomMatrix<T, N, P>(reng, min, max);
                 auto C = A * B;
                 ALWAYS_ASSERT(C.NumRows() == M);
                 ALWAYS_ASSERT(C.NumColumns() == P);
             }
             {
                 const size_t M = 2, N = 3, P = 4;
                 auto A = IdentityMatrix<T, M, N>();
                 auto B = RandomMatrix<T, N, P>(reng, min, max);
                 auto C = A * B;
                 ALWAYS_ASSERT(C.NumRows() == M);
                 ALWAYS_ASSERT(C.NumColumns() == P);
                 // Submatrix?
             }

             const size_t M = 3, N = 3;

             auto A = RandomMatrix<T, M, N>(reng, min, max);
             auto B = RandomMatrix<T, M, N>(reng, min, max);
             auto C = RandomMatrix<T, M, N>(reng, min, max);

             // Associative
             ALWAYS_ASSERT((A * B) * C == A * (B * C));
             // Distributive
             ALWAYS_ASSERT((A + B) * C == A * C + B * C);

             // Commutative if and only if A or B is an diagonal matrix
             if (IsDiagonalMatrix(A) || IsDiagonalMatrix(B))
                 ALWAYS_ASSERT(A* B == B * A);
             // NOT Commutative
             else
                 ALWAYS_ASSERT(A* B != B * A);
         }
    }

    {
    }
}