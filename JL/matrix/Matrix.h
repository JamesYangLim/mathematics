/*
Matrix.h
*/

#pragma once

#include <array>

namespace jl
{
    /*
    N = number of columns 
    M = number of rows
    */
    template <typename T, size_t N, size_t M>
    struct Matrix : std::array<T, N* M>
    {
        Matrix() : std::array<T, N* M>()
        {}
    };

    template<typename T, size_t N, size_t M> std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& A);

    /*
    Rule of thumb for matrix multiplication:
        1. A1.N == A2.M (e.g. A(m x n) * A(n x p) = A(m x p)
        2. NOT commutative (e.g. AB != BA)
        3. Any matrix can be multiplied element-wise by a scalar from its associated field
    */
    template<typename T, size_t N, size_t M> Matrix<T, N, M> operator*(const Matrix<T, N, M>& A1, const Matrix<T, N, M>& A2);
    
    template<typename T, size_t N, size_t M> Matrix<T, N, M> operator*(const Matrix<T, N, M>& A1, T s);
    template<typename T, size_t N, size_t M> Matrix<T, N, M> operator*(T s, const Matrix<T, N, M>& A1);

    // A1.N == A2.M 
    template<typename T, size_t N, size_t M> Matrix<T, N, M> operator+(const Matrix<T, N, M>& A1, const Matrix<T, N, M>& A2);
    
    /*
    A + B = | A 0 |
            | 0 B |
    */
    template<typename T, size_t N, size_t M> Matrix<T, N, M> DirectSum(const Matrix<T, N, M>& A1, const Matrix<T, N, M>& A2);

    template<typename T, size_t N, size_t M> Matrix<T, N, M> Transpose(const Matrix<T, N, M>& A);

    template<typename T, size_t N, size_t M> bool operator==(const Matrix<T, N, M>& A1, const Matrix<T, N, M>& A2);

    template<typename T, size_t N, size_t M> Matrix<T, N, M> IdentityMatrix();
    template<typename T, size_t N, size_t M> Matrix<T, N, M>& InverseMatrix(Matrix<T, N, M>& A);


    //////////////////////////// Implementation

    template<typename T, size_t N, size_t M> 
    std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& A)
    {
        for (size_t m = 0; m < M; ++m)
        {
            for (size_t n = 0; n < N; ++n)
            {
                if (n == 0) os << "|";
                os << " " << A[n * N + m] << " ";
                if (n == N - 1) os << "| \n";
            }
        }
        return os;
    }

    template<typename T, size_t N, size_t M> 
    Matrix<T, N, M> IdentityMatrix()
    {
        Matrix<T, N, M> A;
        for (size_t n = 0; n < N; ++n)
            for (size_t m = 0; m < M; ++m)
                A[n * N + m] = (n == m) ? 1 : 0;
        return A;
    }

}