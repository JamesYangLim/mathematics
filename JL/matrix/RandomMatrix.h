/*
RandomMatrix.h
*/

#pragma once

#include "Matrix.h"

#include "JL/geometry/Random.h"

namespace jl
{
    template<typename T, size_t M, size_t N, typename RandomEng>
    Matrix<T,M,N> RandomMatrix(RandomEng& e, T min, T max)
    {
        ASSERT(min <= max);
        uniform_dist<T> rng(min, max);
        Matrix<T,M,N> a;
        for (size_t i = 0; i < M*N; ++i)
            a[i] = rng(e);
        return a;
    }

} // namespace jl