/*
Matrix.inl
*/

#pragma once

#include "JL/utils/Utils.h"

#include <array>

namespace jl
{
    template<typename T, size_t M, size_t N>
    std::ostream& operator<<(std::ostream& os, const Matrix<T,M,N>& a)
    {
        for(size_t i = 0; i < M*N; ++i)
        {
            os << a[i] << " ";
            if((i+1) % N == 0) os << "\n";
        }
        return os;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T,M,N> operator+(const Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs)
    {
        Matrix<T,M,N> a;
        for (size_t i = 0; i < M*N; ++i)
            a[i] = lhs[i] + rhs[i];
        return a;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T,M,N> operator-(const Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs)
    {
        Matrix<T,M,N> a;
        for (size_t i = 0; i < M*N; ++i)
            a[i] = lhs[i] - rhs[i];
        return a;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T,M,N> operator*(const Matrix<T,M,N>& lhs, T s)
    {
        Matrix<T,M,N> a;
        for (size_t i = 0; i < M*N; ++i)
            a[i] = lhs[i] * s;
        return a;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T,M,N> operator*(T s, const Matrix<T,M,N>& rhs)
    {
        return rhs * s;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T,M,N> operator/(const Matrix<T,M,N>& lhs, T s)
    {
        ASSERT(s != 0);
        Matrix<T,M,N> a;
        for (size_t i = 0; i < M*N; ++i)
            a[i] = lhs[i] / s;
        return a;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T,M,N>& operator+=(Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs)
    {
        for (size_t i = 0; i < M*N; ++i)
            lhs[i] += rhs[i];
        return lhs;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T,M,N>& operator-=(Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs)
    {
        for (size_t i = 0; i < M*N; ++i)
            lhs[i] -= rhs[i];
        return lhs;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T,M,N>& operator*=(Matrix<T,M,N>& lhs, T s)
    {
        for (size_t i = 0; i < M*N; ++i)
            lhs[i] *= s;
        return lhs;
    }

    template<typename T, size_t M, size_t N>
    Matrix<T,M,N>& operator/=(Matrix<T,M,N>& lhs, T s)
    {
        ASSERT(s != 0);
        for (size_t i = 0; i < M*N; ++i)
            lhs[i] /= s;
        return lhs;
    }

    template<typename T, size_t M, size_t N>
    bool operator==(const Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs)
    {
        return lhs.Elements == rhs.Elements;
    }

    template<typename T, size_t M, size_t N>
    bool operator!=(const Matrix<T,M,N>& lhs, const Matrix<T,M,N>& rhs)
    {
        return !(lhs.Elements == rhs.Elements);
    }

    template<typename T, size_t M, size_t N, size_t P> 
    Matrix<T,M,P> operator*(const Matrix<T,M,N>& a1, const Matrix<T,N,P>& a2)
    {
        Matrix<T,M,P> a;
        for (size_t m = 0; m < M; ++m)
            for (size_t p = 0; p < P; ++p)
            {
                T sum = 0;
                for (size_t n = 0; n < N; ++n)
                    sum += a1[m*N+n] * a2[n*P+p];
                a[m*P+p] = sum;
            }
        return a;
    }

    template<typename T, size_t M, size_t N> 
    Matrix<T,M,N> DiagonalMatrix(T v)
    {
        Matrix<T,M,N> a;
        for (size_t m = 0; m < M; ++m)
            for (size_t n = 0; n < N; ++n)
                a[m*N+n] = (m == n) ? v : 0;
        return a;
    }

    template<typename T, size_t M, size_t N>
    bool IsDiagonalMatrix(const Matrix<T,M,N>& a)
    {
        ASSERT(a.size() > 0);
        return a == DiagonalMatrix<T,M,N>(a[0]);
    }
    
    template<typename T, size_t M, size_t N>
    Matrix<T,M,N> IdentityMatrix()
    {
        return DiagonalMatrix<T,M,N>(T(1));
    }

    template<typename T, size_t M, size_t N>
    Matrix<T,N,M> Transpose(const Matrix<T,M,N>& a)
    {
        return Matrix<T,N,M>{a.Elements};
    }

    template<typename T, size_t M, size_t N> 
    Matrix<T,M-1,N-1> Submatrix(const Matrix<T,M,N>& a, int rowToRemove, int columnToRemove)
    {
        ASSERT(0 <= rowToRemove && rowToRemove < M);
        ASSERT(0 <= columnToRemove && columnToRemove < N);

        Matrix<T,M-1,N-1> submatrix;
        size_t i = 0;
        for (size_t m = 0; m < M; ++m)
        {
            if(m == rowToRemove) continue;
            for (size_t n = 0; n < N; ++n)
            {
                if(n == columnToRemove) continue;
                submatrix[i++] = a[m*N+n];
            }
        }
        return submatrix;
    }

    template<typename T, size_t M> 
    T Determinant(const Matrix<T,M,M>& a)
    {
        T d(0);

        if(M > 2)
        {
            for(size_t i = 0; i < M; ++i)
            {
                auto minor = Submatrix(a,0,i);
                
                ASSERT(a.NumRows() == a.NumColumns());
                ASSERT(a.NumRows() == M-1);

                if(i % 2) d += (a[i] * Determinant(minor));
                else      d -= (a[i] * Determinant(minor));
            }
        }
        else if(M == 2)
        {
            d = a[0]*a[3] - a[1]*a[2];
        }
        else if(M == 1)
        {
            d = a[0];
        }
        
        return d;
    }

}