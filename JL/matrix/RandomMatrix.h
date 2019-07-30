/*
RandomMatrix.h
*/

#pragma once

#include "Matrix.h"

#include "JL/geometry/Random.h"

namespace jl
{
    template<typename T, size_t N, size_t M, typename RandomEng>
    Matrix<T, N, M> RandomMatrix(RandomEng& e, T min, T max)
    {
        ASSERT(max >= min);
        uniform_dist<T> rng(min, max);
        Matrix<T, N, M> A;
        for (size_t i = 0; i < N*M; ++i)
        {
            A[i] = rng(e);
        }
        return A;
    }

} // namespace jl