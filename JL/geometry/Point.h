/*
Point.h

Point is a representation of a Euclidean vector to distinguish between vector in computer science and physics.
https://en.wikipedia.org/wiki/Euclidean_vector

*/

#pragma once

#include "JL/utils/Utils.h"

#include <cmath>
#include <array>
#include <cassert>

namespace jl
{
    template <typename T, size_t D>
    struct Point : std::array<T, D>
    {
        template <typename... Values>
        Point(Values... values) : std::array<T,D>({ std::forward<Values>(values)... })
        {}
    };

    template<typename T, size_t D> std::ostream& operator<<(std::ostream& os, const Point<T, D>& v);
    template<typename T, size_t D> Point<T, D> operator+(const Point<T, D>& lhs, const Point<T, D>& rhs);
    template<typename T, size_t D> Point<T, D> operator-(const Point<T, D>& lhs, const Point<T, D>& rhs);
    template<typename T, size_t D> Point<T, D> operator*(const Point<T, D>& lhs, T scalar);
    template<typename T, size_t D> Point<T, D> operator*(T scalar, const Point<T, D>& rhs);
    template<typename T, size_t D> Point<T, D> operator/(const Point<T, D>& lhs, T scalar);
    template<typename T, size_t D> Point<T, D>& operator+=(Point<T, D>& lhs, const Point<T, D>& rhs);
    template<typename T, size_t D> Point<T, D>& operator-=(Point<T, D>& lhs, const Point<T, D>& rhs);
    template<typename T, size_t D> Point<T, D>& operator*=(Point<T, D>& lhs, T scalar);
    template<typename T, size_t D> Point<T, D>& operator/=(Point<T, D>& lhs, T scalar);

    template<typename T, size_t D> Point<T, D>& operator-(Point<T, D>& p);

    template<typename T, size_t D> bool operator==(const Point<T, D>& lhs, const Point<T, D>& rhs);
    template<typename T, size_t D> bool operator!=(const Point<T, D>& lhs, const Point<T, D>& rhs);

    template<typename T, size_t D> T DotProduct(const Point<T, D>& lhs, const Point<T, D>& rhs);
    template<typename T, size_t D> T ScalarTripleProduct(const Point<T, D>& a, const Point<T, D>& b, const Point<T, D>& c);
    template<typename T, size_t D> T MagnitudeSquare(const Point<T, D>& p);
    template<typename T, size_t D> T Magnitude(const Point<T, D>& p);
    template<typename T, size_t D> Point<T, D>& Normalise(Point<T, D>& p);
    template<typename T, size_t D> Point<T, D> Repeat(T v);
    template<typename T, size_t D> Point<T, D> Zero();
    template<typename T, size_t D> T AngleBetween(const Point<T, D>& lhs, const Point<T, D>& rhs);

    //////////////////////////// Point2

    template<typename T> using Point2 = Point<T, 2>;
    using Point2i = Point2<int32_t>;
    using Point2f = Point2<float>;
    using Point2d = Point2<double>;

    template<typename T> T CrossProduct(const Point2<T>& lhs, const Point2<T>& rhs);

    //////////////////////////// Point3

    template<typename T> using Point3 = Point<T, 3>;
    using Point3i = Point3<int32_t>;
    using Point3f = Point3<float>;
    using Point3d = Point3<double>;

    template<typename T> Point3<T> CrossProduct(const Point3<T>& lhs, const Point3<T>& rhs);

    //////////////////////////// Implementation

    template<typename T, size_t D>
    std::ostream& operator<<(std::ostream& os, const Point<T, D>& v)
    {
        os << "(";
        for (int i = 0; i < v.size(); ++i)
        {
            if (i > 0) 
                os << ',';
            os << v[i];
        }
        os << ")";
        return os;
    }

    template<typename T, size_t D> 
    Point<T, D> operator+(const Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        ASSERT(lhs.size() == rhs.size());
        Point<T, D> r;
        for (size_t i = 0; i < lhs.size(); ++i)
            r[i] = lhs[i] + rhs[i];
        return r;
    }

    template<typename T, size_t D>
    Point<T, D> operator-(const Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        ASSERT(lhs.size() == rhs.size());
        Point<T, D> r;
        for (size_t i = 0; i < lhs.size(); ++i)
            r[i] = lhs[i] - rhs[i];
        return r;
    }

    template<typename T, size_t D> 
    Point<T, D> operator*(const Point<T, D>& lhs, T scalar)
    {
        Point<T, D> r;
        for (size_t i = 0; i < lhs.size(); ++i)
            r[i] = lhs[i] * scalar;
        return r;
    }

    template<typename T, size_t D> 
    Point<T, D> operator*(T scalar, const Point<T, D>& rhs)
    {
        return rhs * scalar;
    }

    template<typename T, size_t D> 
    Point<T, D> operator/(const Point<T, D>& lhs, T scalar)
    {
        Point<T, D> r;
        for (size_t i = 0; i < lhs.size(); ++i)
            r[i] = lhs[i] / scalar;
        return r;
    }

    template<typename T, size_t D> 
    Point<T, D>& operator+=(Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        ASSERT(lhs.size() == rhs.size());
        for (size_t i = 0; i < lhs.size(); ++i)
            lhs[i] += rhs[i];
        return lhs;
    }

    template<typename T, size_t D> 
    Point<T, D>& operator-=(Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        ASSERT(lhs.size() == rhs.size());
        for (size_t i = 0; i < lhs.size(); ++i)
            lhs[i] -= rhs[i];
        return lhs;
    }

    template<typename T, size_t D> 
    Point<T, D>& operator*=(Point<T, D>& lhs, T scalar)
    {
        for (size_t i = 0; i < lhs.size(); ++i)
            lhs[i] *= scalar;
        return lhs;
    }

    template<typename T, size_t D> 
    Point<T, D>& operator/=(Point<T, D>& lhs, T scalar)
    {
        for (size_t i = 0; i < lhs.size(); ++i)
            lhs[i] /= scalar;
        return lhs;
    }

    template<typename T, size_t D> 
    Point<T, D>& operator-(Point<T, D>& p)
    {
        return p *= (T)-1;
    }

    template<typename T, size_t D> 
    T DotProduct(const Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        ASSERT(lhs.size() == rhs.size());
        T sum = 0;
        for (size_t i = 0; i < lhs.size(); ++i)
            sum += lhs[i] * rhs[i];
        return sum;
    }

    template<typename T> 
    T CrossProduct(const Point2<T>& lhs, const Point2<T>& rhs)
    {
        return (lhs[0] * rhs[1]) - (lhs[1] * rhs[0]);
    }

    template<typename T> 
    Point3<T> CrossProduct(const Point3<T>& lhs, const Point3<T>& rhs)
    {
        return Point3<T>(
            (lhs[1] * rhs[2]) - (lhs[2] * rhs[1]),
            (lhs[2] * rhs[0]) - (lhs[0] * rhs[2]),
            (lhs[0] * rhs[1]) - (lhs[1] * rhs[0]));
    }

    template<typename T, size_t D> 
    T ScalarTripleProduct(const Point<T, D>& a, const Point<T, D>& b, const Point<T, D>& c)
    {
        return DotProduct(a, CrossProduct(b, c));
    }

    template<typename T, size_t D> 
    bool operator==(const Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        ASSERT(lhs.size() == rhs.size());
        for (size_t i = 0; i < lhs.size(); ++i)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    }

    template<typename T, size_t D> 
    bool operator!=(const Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        return !(lhs == rhs);
    }

    template<typename T, size_t D> 
    T MagnitudeSquare(const Point<T, D>& p)
    {
        return DotProduct(p, p);
    }

    template<typename T, size_t D> 
    T Magnitude(const Point<T, D>& p)
    {
        return std::sqrt(MagnitudeSquare(p));
    }

    template<typename T, size_t D> 
    Point<T, D>& Normalise(Point<T, D>& p)
    {
        T m = Magnitude(p);
        for (size_t i = 0; i < p.size(); ++i)
            p[i] / m;
        return p;
    }

    template<typename T, size_t D> 
    Point<T, D> Repeat(T v)
    {
        Point<T, D> p;
        for (size_t i = 0; i < p.size(); ++i)
            p[i] = v;
        return p;
    }

    template<typename T, size_t D> 
    Point<T, D> Zero()
    {
        return Repeat<T, D>(0);
    }

    template<typename T, size_t D> 
    T AngleBetween(const Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        return std::acos(DotProduct(lhs, rhs) / std::sqrt(MagnitudeSquare(lhs) * MagnitudeSquare(rhs)));
    }

} // namespace jl