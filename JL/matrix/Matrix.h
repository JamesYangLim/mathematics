/*
Matrix.h
*/

#pragma once

#include <iostream>

namespace jl
{
    /*
    N = number of columns 
    M = number of rows
    */
    template <typename T, size_t N, size_t M> struct Matrix;

    template<typename T, size_t N, size_t M> std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& A);

    template<typename T, size_t N, size_t M> Matrix<T, N, M> operator+(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs);
    template<typename T, size_t N, size_t M> Matrix<T, N, M> operator-(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs);
    template<typename T, size_t N, size_t M> Matrix<T, N, M> operator*(const Matrix<T, N, M>& lhs, T s);
    template<typename T, size_t N, size_t M> Matrix<T, N, M> operator*(T s, const Matrix<T, N, M>& rhs);
    template<typename T, size_t N, size_t M> Matrix<T, N, M> operator/(const Matrix<T, N, M>& lhs, T s);

    template<typename T, size_t N, size_t M> Matrix<T, N, M>& operator+=(Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs);
    template<typename T, size_t N, size_t M> Matrix<T, N, M>& operator-=(Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs);
    template<typename T, size_t N, size_t M> Matrix<T, N, M>& operator*=(Matrix<T, N, M>& lhs, T s);
    template<typename T, size_t N, size_t M> Matrix<T, N, M>& operator/=(Matrix<T, N, M>& lhs, T s);

    template<typename T, size_t N, size_t M> Matrix<T, M, N> Transpose(const Matrix<T, N, M>& A);



    template<typename T, size_t N, size_t M> bool operator==(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs);
    template<typename T, size_t N, size_t M> bool operator!=(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs);


    /*
    Rule of thumb for matrix multiplication:
        1. A1.N == A2.M (e.g. A(m x n) * A(n x p) = A(m x p)
        2. NOT commutative (e.g. AB != BA)
        3. Any matrix can be multiplied element-wise by a scalar from its associated field
    */
    template<typename T, size_t N, size_t M> Matrix<T, N, M> operator*(const Matrix<T, N, M>& A1, const Matrix<T, N, M>& A2);
    

    
    /*
    A + B = | A 0 |
            | 0 B |
    */
    template<typename T, size_t N, size_t M> Matrix<T, N, M> DirectSum(const Matrix<T, N, M>& A1, const Matrix<T, N, M>& A2);



    template<typename T, size_t N, size_t M> Matrix<T, N, M> IdentityMatrix();
    template<typename T, size_t N, size_t M> Matrix<T, N, M>& InverseMatrix(Matrix<T, N, M>& A);
}

#include "detail/Matrix.inl"
