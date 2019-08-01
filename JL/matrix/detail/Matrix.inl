/*
Matrix.inl
*/

#pragma once

#include "JL/utils/Utils.h"

#include <array>

namespace jl
{
    template <typename T, size_t N, size_t M>
    struct Matrix
    {
        using Coords = std::array<T, N* M>;

        Coords Elements;

        template <typename... Values>
        Matrix(Values... values) : Elements(std::array<T, N* M>({ std::forward<Values>(values)... }))
        {}

        const size_t NumColumns() const { return N; }
        const size_t NumRows() const { return M; }
        T& operator[](size_t i) { return Elements[i]; }
        const T& operator[](size_t i) const { return Elements[i]; }
    };

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

    template<typename T, size_t N, size_t M>
    Matrix<T, N, M> operator+(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs)
    {
        Matrix<T, N, M> A;
        for (size_t i = 0; i < N * M; ++i)
            A[i] = lhs[i] + rhs[i];
        return A;
    }

    template<typename T, size_t N, size_t M>
    Matrix<T, N, M> operator-(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs)
    {
        Matrix<T, N, M> A;
        for (size_t i = 0; i < N * M; ++i)
            A[i] = lhs[i] - rhs[i];
        return A;
    }

    template<typename T, size_t N, size_t M>
    Matrix<T, N, M> operator*(const Matrix<T, N, M>& lhs, T s)
    {
        Matrix<T, N, M> A;
        for (size_t i = 0; i < N * M; ++i)
            A[i] = lhs[i] * s;
        return A;
    }

    template<typename T, size_t N, size_t M>
    Matrix<T, N, M> operator*(T s, const Matrix<T, N, M>& rhs)
    {
        return rhs * s;
    }

    template<typename T, size_t N, size_t M>
    Matrix<T, N, M> operator/(const Matrix<T, N, M>& lhs, T s)
    {
        ASSERT(s != 0);
        Matrix<T, N, M> A;
        for (size_t i = 0; i < N * M; ++i)
            A[i] = lhs[i] / s;
        return A;
    }

    template<typename T, size_t N, size_t M>
    Matrix<T, N, M>& operator+=(Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs)
    {
        for (size_t i = 0; i < N * M; ++i)
            lhs[i] += rhs[i];
        return lhs;
    }

    template<typename T, size_t N, size_t M>
    Matrix<T, N, M>& operator-=(Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs)
    {
        for (size_t i = 0; i < N * M; ++i)
            lhs[i] -= rhs[i];
        return lhs;
    }

    template<typename T, size_t N, size_t M>
    Matrix<T, N, M>& operator*=(Matrix<T, N, M>& lhs, T s)
    {
        for (size_t i = 0; i < N * M; ++i)
            lhs[i] *= s;
        return lhs;
    }

    template<typename T, size_t N, size_t M>
    Matrix<T, N, M>& operator/=(Matrix<T, N, M>& lhs, T s)
    {
        ASSERT(s != 0);
        for (size_t i = 0; i < N * M; ++i)
            lhs[i] /= s;
        return lhs;
    }

    template<typename T, size_t N, size_t M>
    bool operator==(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs)
    {
        return lhs.Elements == rhs.Elements;
    }

    template<typename T, size_t N, size_t M>
    bool operator!=(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs)
    {
        return !(lhs.Elements == rhs.Elements);
    }

    template<typename T, size_t N, size_t M>
    Matrix<T, M, N> Transpose(const Matrix<T, N, M>& A)
    {
        Matrix<T, M, N> tA;
        for (size_t i = 0; i < N * M; ++i)
            tA[i] = A[i];
        return tA;
    }
}