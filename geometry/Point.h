/*
Point.h 
*/

#pragma once

#include <array>
#include <cassert>

namespace geom
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
    template<typename T, size_t D> T DotProduct(const Point<T, D>& lhs, const Point<T, D>& rhs);

    //////////////////////////// Point2

    template<typename T> using Point2 = Point<T, 2>;
    using Point2i = Point2<int>;
    using Point2f = Point2<float>;
    using Point2d = Point2<double>;

    template<typename T> T CrossProduct(const Point2<T>& lhs, const Point2<T>& rhs);

    //////////////////////////// Point3

    template<typename T> using Point3 = Point<T, 3>;
    using Point3i = Point3<int>;
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
            {
                os << ',';
            }
            os << v[i];
        }
        os << ")";
        return os;
    }

    template<typename T, size_t D> 
    Point<T, D> operator+(const Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        assert(lhs.size() == rhs.size());
        Point<T, D> r;
        for (size_t i = 0; i < lhs.size(); ++i)
            r[i] = lhs[i] + rhs[i];
        return r;
    }

    template<typename T, size_t D>
    Point<T, D> operator-(const Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        assert(lhs.size() == rhs.size());
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
        return rhs * (1.0 / scalar);
    }

    template<typename T, size_t D> 
    Point<T, D>& operator+=(Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        assert(lhs.size() == rhs.size());
        for (size_t i = 0; i < lhs.size(); ++i)
            lhs[i] += rhs[i];
        return lhs;
    }

    template<typename T, size_t D> 
    Point<T, D>& operator-=(Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        assert(lhs.size() == rhs.size());
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
        return lhs *= (1.0 / scalar);
    }

    template<typename T, size_t D> 
    T DotProduct(const Point<T, D>& lhs, const Point<T, D>& rhs)
    {
        assert(lhs.size() == rhs.size());
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

}