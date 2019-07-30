/*
LinearTransformation.h

https://en.wikipedia.org/wiki/Transformation_matrix

Av = T(v) where,
    A = Transformation matrix
    v = vector
    T(v) = Transformed vector

Linear transformation keep the origin fixed.

*/

#pragma once

#include "JL/matrix/Matrix.h"
#include "JL/geometry/Point.h"

namespace jl
{
    template<typename T, size_t D> Matrix<T, D, D> ScaleMatrix(T factor);

    //////////////////////////// Implementation

    template<typename T, size_t D> 
    Matrix<T, D, D> ScaleMatrix(T factor)
    {

    }

}