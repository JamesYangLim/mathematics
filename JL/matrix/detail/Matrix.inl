/*
Matrix.inl
*/

#pragma once

#include "JL/utils/Utils.h"

#include <array>

namespace jl
{
    template <typename T, size_t M, size_t N>
    struct Matrix
    {
        using Coords = std::array<T, M * N>;
        using CoordType = typename Coords::value_type;

        Coords Elements;

        template <typename... Values>
        Matrix(Values... values) : Elements(std::array<T, M * N>({ std::forward<Values>(values)... }))
        {}

        const size_t size() const { return Elements.size(); }
        const size_t NumColumns() const { return N; }
        const size_t NumRows() const { return M; }
        T& operator[](size_t i) { return Elements[i]; }
        const T& operator[](size_t i) const { return Elements[i]; }

    };

    template<typename T, size_t M, size_t N>
    std::ostream& operator<<(std::ostream& os, const Matrix<T, M, N>& A)
    {
        for (size_t m = 0; m < M; ++m)
        {
            for (size_t n = 0; n < N; ++n)
            {
                if (n == 0)     os << "|";
                os << " " << A[n + m * M] << " ";
                if (n == N - 1) os << "| \n";
            }
        }
        return os;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T, M, N> operator+(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs)
    {
        Matrix<T, M, N> A;
        for (size_t i = 0; i < M * N; ++i)
            A[i] = lhs[i] + rhs[i];
        return A;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T, M, N> operator-(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs)
    {
        Matrix<T, M, N> A;
        for (size_t i = 0; i < M * N; ++i)
            A[i] = lhs[i] - rhs[i];
        return A;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T, M, N> operator*(const Matrix<T, M, N>& lhs, T s)
    {
        Matrix<T, M, N> A;
        for (size_t i = 0; i < M * N; ++i)
            A[i] = lhs[i] * s;
        return A;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T, M, N> operator*(T s, const Matrix<T, M, N>& rhs)
    {
        return rhs * s;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T, M, N> operator/(const Matrix<T, M, N>& lhs, T s)
    {
        ASSERT(s != 0);
        Matrix<T, M, N> A;
        for (size_t i = 0; i < M * N; ++i)
            A[i] = lhs[i] / s;
        return A;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T, M, N>& operator+=(Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs)
    {
        for (size_t i = 0; i < M * N; ++i)
            lhs[i] += rhs[i];
        return lhs;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T, M, N>& operator-=(Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs)
    {
        for (size_t i = 0; i < M * N; ++i)
            lhs[i] -= rhs[i];
        return lhs;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T, M, N>& operator*=(Matrix<T, M, N>& lhs, T s)
    {
        for (size_t i = 0; i < M * N; ++i)
            lhs[i] *= s;
        return lhs;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T, M, N>& operator/=(Matrix<T, M, N>& lhs, T s)
    {
        ASSERT(s != 0);
        for (size_t i = 0; i < M * N; ++i)
            lhs[i] /= s;
        return lhs;
    }

    template<typename T, size_t M, size_t N>
    bool operator==(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs)
    {
        return lhs.Elements == rhs.Elements;
    }

    template<typename T, size_t M, size_t N>
    bool operator!=(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs)
    {
        return !(lhs.Elements == rhs.Elements);
    }

    template<typename T, size_t M, size_t N>
    Matrix<T, N, M> Transpose(const Matrix<T, M, N>& A)
    {
        Matrix<T, N, M> tA;
        for (size_t i = 0; i < M * N; ++i)
            tA[i] = A[i];
        return tA;
    }

    template<typename T, size_t M, size_t N, size_t P> 
    Matrix<T, M, P> operator*(const Matrix<T, M, N>& A1, const Matrix<T, N, P>& A2)
    {
        Matrix<T, M, P> A;
        for (size_t m = 0; m < M; ++m)
        {
            for (size_t p = 0; p < P; ++p)
            {
                T sum = 0;
                for (size_t n = 0; n < N; ++n)
                    sum += A1[m * N + n] * A2[n * P + p];
                A[m * P + p] = sum;
            }
        }
        return A;
    }

    template<typename T, size_t M, size_t N> 
    Matrix<T, M, N> DiagonalMatrix(T v)
    {
        Matrix<T, M, N> A;
        for (size_t m = 0; m < M; ++m)
            for (size_t n = 0; n < N; ++n)
                A[n + m * M] = (n == m) ? v : 0;
        return A;
    }

    template<typename T, size_t M, size_t N>
    bool IsDiagonalMatrix(const Matrix<T, M, N>& A)
    {
        ASSERT(A.size() > 0);
        return A == DiagonalMatrix<T, M, N>(A[0]);
    }
    
    template<typename T, size_t M, size_t N>
    Matrix<T, M, N> IdentityMatrix()
    {
        return DiagonalMatrix<T, M, N>(1);
    }

    template<typename T, size_t M, size_t N> 
    Matrix<T, M, N>& InverseMatrix(Matrix<T, M, N>& A)
    {
    }
}