/*
Matrix.h
*/

#pragma once

#include <array>

namespace jl
{
    /*
    C = number of columns 
    R = number of rows
    */
    template <typename T, size_t C, size_t R>
    struct Matrix : std::array<std::array<T, R>, C>
    {
        Matrix() : std::array<std::array<T, R>, C>()
        {}
    };

    template<typename T, size_t C, size_t R> std::ostream& operator<<(std::ostream& os, const Matrix<T, C, R>& v);

    template<typename T, size_t C, size_t R> Matrix<T, C, R> IdentityMatrix();


    //////////////////////////// Implementation

    template<typename T, size_t C, size_t R> 
    std::ostream& operator<<(std::ostream& os, const Matrix<T, C, R>& A)
    {
        for (size_t r = 0; r < R; ++r)
        {
            for (size_t c = 0; c < C; ++c)
            {
                if (c == 0) os << "|";
                os << " " << A[c][r] << " ";
                if (c == C - 1) os << "| \n";
            }
        }
        return os;
    }

    template<typename T, size_t C, size_t R> 
    Matrix<T, C, R> IdentityMatrix()
    {
        Matrix<T, C, R> A;
        for (size_t c = 0; c < C; ++c)
            for (size_t r = 0; r < R; ++r)
                A[c][r] = (c == r) ? 1 : 0;
        return A;
    }

}