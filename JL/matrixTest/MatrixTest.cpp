/*
MatrixTest.cpp
*/

#include "JL/matrix/Matrix.h"
#include "JL/matrix/RandomMatrix.h"

#include <iostream>


void TestMatrix()
{
    std::cout << "##### Matrix Test #####\n";

    using namespace jl;

    using T = int32_t;
    const T min = -10, max = 10;
    
    uniform_dist<T> rnInt32(min, max);
    auto reng = GetRandomEngine();

    {
        auto a = DiagonalMatrix<T,3,3>(1);
        std::cout << a;
    }

    // Addition
    {
         std::cout << "Test 1: Addition test\n";

        const size_t M = 3, N = 3;

        for (size_t i = 0; i < 1; ++i)
        {
            auto a = RandomMatrix<T,M,N>(reng, min, max);
            auto b = RandomMatrix<T,M,N>(reng, min, max);

            auto c = a + b;
            a += b;
            ALWAYS_ASSERT(a == c);

            c = b - a;
            b -= a;
            ALWAYS_ASSERT(b == c);
        }
    }

    // Scalar multiplication
    {
        std::cout << "Test 2: Scalar multiplication test\n";

        const size_t M = 3, N = 3;

        for (size_t i = 0; i < 1000; ++i)
        {
            auto a = RandomMatrix<T,M,N>(reng, min, max);

            T s = rnInt32(reng);
            if (s == 0) ++s;

            auto b = s * a;
            a *= s;
            ALWAYS_ASSERT(a == b);

            b = b / s;
            a /= s;
            ALWAYS_ASSERT(a == b);
        }
    }

    // Transposition
    {
        std::cout << "Test 3: Transposition test\n";

        /*
        5. det(T(a)) = det(a)
        6. [a.b] = T(a)b
        7. If a has only real entries, then T(a)a is a positive-semidefinite matrix.
        8. Inv(T(a)) = T(Inv(a))
        9. If a is a square matrix, then its eigenvalues are equal to the eigenvalues of its transpose, since they share the same characteristic polynomial.
        */

        const size_t M = 3, N = 3;

        for (size_t i = 0; i < 1000; ++i)
        {
            // T(T(a)) = a
            {
                const size_t M = 3, N = 2;

                auto a = RandomMatrix<T,M,N>(reng, min, max);
                auto b = Transpose(a);
                auto c = Transpose(b);

                ALWAYS_ASSERT(a.NumColumns() == b.NumRows());
                ALWAYS_ASSERT(a.NumRows() == b.NumColumns());
                ALWAYS_ASSERT(a == c);
            }
            // T(a + b) =  T(a) + T(b)
            {
                auto a = RandomMatrix<T,M,N>(reng, min, max);
                auto b = RandomMatrix<T,M,N>(reng, min, max);
                ALWAYS_ASSERT((a + b) == (Transpose(a) + Transpose(b)));
            }
            // T(AB) = T(b)T(a)
            {
                auto a = RandomMatrix<T,M,N>(reng, min, max);
                auto b = RandomMatrix<T,M,N>(reng, min, max);
                ALWAYS_ASSERT((a * b) == (Transpose(a) * Transpose(b)));
            }
            // T(cA) = cT(a)
            {
                auto a = RandomMatrix<T,M,N>(reng, min, max);
                T s = rnInt32(reng);
                ALWAYS_ASSERT((s * a) == (s * Transpose(a)));
            }
        }
    }

    // Matrix multiplication
    {
         std::cout << "Test 4: Matrix multiplication test\n";

         for (size_t i = 0; i < 1000; ++i)
         {
             {
                 const size_t M = 2, N = 3, P = 2;
                 auto a = RandomMatrix<T,M,N>(reng, min, max);
                 auto b = RandomMatrix<T,N,P>(reng, min, max);
                 auto c = a * b;
                 ALWAYS_ASSERT(c.NumRows() == M);
                 ALWAYS_ASSERT(c.NumColumns() == P);
             }
             {
                 const size_t M = 2, N = 3, P = 4;
                 auto a = RandomMatrix<T,M,N>(reng, min, max);
                 auto b = RandomMatrix<T,N,P>(reng, min, max);
                 auto c = a * b;
                 ALWAYS_ASSERT(c.NumRows() == M);
                 ALWAYS_ASSERT(c.NumColumns() == P);
             }
             {
                 const size_t M = 2, N = 3, P = 4;
                 auto a = IdentityMatrix<T,M,N>();
                 auto b = RandomMatrix<T,N,P>(reng, min, max);
                 auto c = a * b;
                 ALWAYS_ASSERT(c.NumRows() == M);
                 ALWAYS_ASSERT(c.NumColumns() == P);
                 // Submatrix?
             }

             const size_t M = 3, N = 3;

             auto a = RandomMatrix<T,M,N>(reng, min, max);
             auto b = RandomMatrix<T,M,N>(reng, min, max);
             auto c = RandomMatrix<T,M,N>(reng, min, max);

             // Associative
             ALWAYS_ASSERT((a * b) * c == a * (b * c));
             // Distributive
             ALWAYS_ASSERT((a + b) * c == a * c + b * c);

             // Commutative if and only if a or b is an diagonal matrix
             if (IsDiagonalMatrix(a) || IsDiagonalMatrix(b))
                 ALWAYS_ASSERT(a* b == b * a);
             // NOT Commutative
             else
                 ALWAYS_ASSERT(a* b != b * a);
         }
    }

    // Submatrix
    {
        std::cout << "Test 5: Submatrix test\n";
        {
            const size_t M=3, N=3;
            auto a = RandomMatrix<T,M,N>(reng, min, max);

            Matrix<T,M-1,N-1> sub = Submatrix(a, 0, 1);
            std::cout << sub;
        }
    }

    // Determinant
    {
        std::cout << "Test 6: Determinant test\n";
        /*
        Properties:
        1. det(In) = 1 where In is the n x n identity matrix.
        2. det(T(A)) = det(A), where T(A) denotes the transpose of A.
        3. det(Inv(A)) = 1/det(A) = Inv(det(A)).
        4. For square matrices A and B of equal size, det(AB) = det(A)det(B).
        5. det(cA) = c^n det(A) for an n x n matrix, A.
        */
        {
            const size_t M=3, N=3;
            auto a = RandomMatrix<T,M,N>(reng, min, max);

            T d = Determinant(a);
        }

    }
}