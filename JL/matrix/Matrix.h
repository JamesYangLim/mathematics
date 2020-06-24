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
    */
    template <typename T, size_t M, size_t N>
    struct Matrix
    {
        using Coords = std::array<T,M*N>;
        using CoordType = typename Coords::value_type;

        Coords Elements;

        template <typename... Values>
        Matrix(Values... values) : Elements(std::array<T,M*N>({ std::forward<Values>(values)... }))
        {}

        const size_t size() const { return Elements.size(); }
        const size_t NumColumns() const { return N; }
        const size_t NumRows() const { return M; }
        T& operator[](size_t i) { return Elements[i]; }
        const T& operator[](size_t i) const { return Elements[i]; }
    };
    
    template<typename T, size_t M, size_t N> std::ostream& operator<<(std::ostream& os, const Matrix<T,M,N>& a);

    template<typename T, size_t M, size_t N> Matrix<T,M,N> operator+(const Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs);
    template<typename T, size_t M, size_t N> Matrix<T,M,N> operator-(const Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs);
    template<typename T, size_t M, size_t N> Matrix<T,M,N> operator*(const Matrix<T,M,N>& lhs, T s);
    template<typename T, size_t M, size_t N> Matrix<T,M,N> operator*(T s, const Matrix<T, N, N>& rhs);
    template<typename T, size_t M, size_t N> Matrix<T,M,N> operator/(const Matrix<T,M,N>& lhs, T s);
    template<typename T, size_t M, size_t N> Matrix<T,M,N>& operator+=(Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs);
    template<typename T, size_t M, size_t N> Matrix<T,M,N>& operator-=(Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs);
    template<typename T, size_t M, size_t N> Matrix<T,M,N>& operator*=(Matrix<T,M,N>& lhs, T s);
    template<typename T, size_t M, size_t N> Matrix<T,M,N>& operator/=(Matrix<T,M,N>& lhs, T s);
    /*
    Rule of thumb for matrix multiplication:
        1. A1.N == A2.M (e.g. a(m x n) * a(n x p) = a(m x p)
        2. NOT commutative (e.g. AB != BA)
        3. Any matrix can be multiplied element-wise by a scalar from its associated field
    */
    template<typename T, size_t M, size_t N, size_t P> Matrix<T,M,P> operator*(const Matrix<T,M,N>& a1, const Matrix<T,N,P>& a2);

    template<typename T, size_t M, size_t N> bool operator==(const Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs);
    template<typename T, size_t M, size_t N> bool operator!=(const Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs);

    // a diagonal matrix is an identity matrix multiply with a scalar value
    template<typename T, size_t M, size_t N> Matrix<T,M,N> DiagonalMatrix(T v);
    template<typename T, size_t M, size_t N> bool IsDiagonalMatrix(const Matrix<T,M,N>& a);
    template<typename T, size_t M, size_t N> Matrix<T,M,N> IdentityMatrix();
    template<typename T, size_t M, size_t N> Matrix<T,N,M> Transpose(const Matrix<T,M,N>& a);
    
    template<typename T, size_t M, size_t N> Matrix<T,M-1,N-1> Submatrix(const Matrix<T,M,N>& a, int rowToRemove, int columnToRemove);
    template<typename T, size_t M> T Determinant(const Matrix<T,M,M>& a);

    template<typename T, size_t N> Matrix<T, N, N>& InverseMatrix(Matrix<T, N, N>& a);

    /*
    a + B = | a 0 |
            | 0 B |
    */
    template<typename T, size_t M, size_t N> Matrix<T,M,N> DirectSum(const Matrix<T,M,N>& A1, const Matrix<T,M,N>& A2);


}

#include "detail/Matrix.inl"
