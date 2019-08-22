/*
Matrix.h
*/

#pragma once

#include <iostream>

namespace jl
{
    /*
    Matrix, A has a size of M x N (or M by N), where 
        M = number of rows 
        N = number of columns

    e.g. 
        3x2 Matrix, A:      2x3 Matrix, A:          3x3 Matrix, A:
            | ix jx |           | ix jx kx |            | ix jx kx |
            | iy jy |           | iy jy ky | 2x3        | iy jy ky |
            | iz jz | 3x2                               | iz jz kz | 3x3
    */
    template<typename T, size_t M, size_t N> struct Matrix;

    template<typename T, size_t M, size_t N> std::ostream& operator<<(std::ostream& os, const Matrix<T, M, N>& A);

    template<typename T, size_t M, size_t N> Matrix<T, M, N> operator+(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs);
    template<typename T, size_t M, size_t N> Matrix<T, M, N> operator-(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs);
    template<typename T, size_t M, size_t N> Matrix<T, M, N> operator*(const Matrix<T, M, N>& lhs, T s);
    template<typename T, size_t M, size_t N> Matrix<T, M, N> operator*(T s, const Matrix<T, N, N>& rhs);
    template<typename T, size_t M, size_t N> Matrix<T, M, N> operator/(const Matrix<T, M, N>& lhs, T s);

    template<typename T, size_t M, size_t N> Matrix<T, M, N>& operator+=(Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs);
    template<typename T, size_t M, size_t N> Matrix<T, M, N>& operator-=(Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs);
    template<typename T, size_t M, size_t N> Matrix<T, M, N>& operator*=(Matrix<T, M, N>& lhs, T s);
    template<typename T, size_t M, size_t N> Matrix<T, M, N>& operator/=(Matrix<T, M, N>& lhs, T s);

    template<typename T, size_t M, size_t N> Matrix<T, N, M> Transpose(const Matrix<T, M, N>& A);

    template<typename T, size_t M, size_t N> bool operator==(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs);
    template<typename T, size_t M, size_t N> bool operator!=(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs);

     /*
    Rule of thumb for matrix multiplication:
        1. A1.N == A2.M (e.g. A(m x n) * A(n x p) = A(m x p)
        2. NOT commutative (e.g. AB != BA)
        3. Any matrix can be multiplied element-wise by a scalar from its associated field
    */
    template<typename T, size_t M, size_t N, size_t P> 
    Matrix<T, M, P> operator*(const Matrix<T, M, N>& A1, const Matrix<T, N, P>& A2);

    /*
    A + B = | A 0 |
            | 0 B |
    */
    template<typename T, size_t M, size_t N> Matrix<T, M, N> DirectSum(const Matrix<T, M, N>& A1, const Matrix<T, M, N>& A2);

    // A diagonal matrix is an identity matrix multiply with a scalar value
    template<typename T, size_t M, size_t N> Matrix<T, M, N> DiagonalMatrix(T v);
    template<typename T, size_t M, size_t N> bool IsDiagonalMatrix(const Matrix<T, M, N>& A);
    template<typename T, size_t M, size_t N> Matrix<T, M, N> IdentityMatrix();

    template<typename T, size_t M, size_t N> Matrix<T, M, N>& InverseMatrix(Matrix<T, M, N>& A);

    template<typename T, size_t M> using MatrixSqd = Matrix<T, M, M>;
}

#include "detail/Matrix.inl"
