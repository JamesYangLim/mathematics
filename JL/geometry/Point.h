/*
Point.h

Point is a representation of a Euclidean vector to distinguish between vector in computer science and physics.

https://en.wikipedia.org/wiki/Euclidean_vector
https://en.wikipedia.org/wiki/Vector_space#Definition

Definition:
    V = vector set
    v, u, w = vector
    0 = zero vector
    F = field
    a, b = scalar (elements of F)

Axioms:
    Associative addition:   u + (v + w) = (u + v) + w
    Commutative addition:   u + v = v + u
    Identity element of addition:   There exist 0 in V -> v + 0 = v for all v in V
    Inverse elements of addition:   For all v in V, there exist -v in V -> v + (-v) = 0
    Compatibility of scalar multiplication with field multiplication:   a(bv) = (ab)v
    Identity element of scalar multiplication:  1 * v = v, 1 denotes multiplicative identity in F
    Distributivity of scalar multiplication with respect to vector addition:    a(u + v) = au + av
    Distributivity of scalar multiplication with respect to field addition:     (a + b)v = av + bv
*/

#pragma once

#include <ostream>

namespace jl
{
    template <typename T, size_t D> using Point = std::array<T, D>;

    template<typename T, size_t D> std::ostream& operator<<(std::ostream& os, const Point<T,D>& v);
    template<typename T, size_t D> Point<T,D> operator+(const Point<T,D>& lhs, const Point<T,D>& rhs);
    template<typename T, size_t D> Point<T,D> operator-(const Point<T,D>& lhs, const Point<T,D>& rhs);
    template<typename T, size_t D> Point<T,D>& operator-(Point<T,D>& p);
    template<typename T, size_t D> Point<T,D> operator*(const Point<T,D>& lhs, T s);
    template<typename T, size_t D> Point<T,D> operator*(T s, const Point<T,D>& rhs);
    template<typename T, size_t D> Point<T,D> operator/(const Point<T,D>& lhs, T s);

    template<typename T, size_t D> Point<T,D>& operator+=(Point<T,D>& lhs, const Point<T,D>& rhs);
    template<typename T, size_t D> Point<T,D>& operator-=(Point<T,D>& lhs, const Point<T,D>& rhs);
    template<typename T, size_t D> Point<T,D>& operator*=(Point<T,D>& lhs, T s);
    template<typename T, size_t D> Point<T,D>& operator/=(Point<T,D>& lhs, T s);

    template<typename T, size_t D> T DotProduct(const Point<T,D>& lhs, const Point<T,D>& rhs);
    template<typename T, size_t D> T ScalarTripleProduct(const Point<T,D>& a, const Point<T,D>& b, const Point<T,D>& c);

    template<typename T, size_t D> T MagnitudeSquare(const Point<T,D>& p);
    template<typename T, size_t D> T Magnitude(const Point<T,D>& p);
    template<typename T, size_t D> Point<T,D>& Normalise(Point<T,D>& p);
    
    template<typename T, size_t D> Point<T,D> Repeat(T v);
    template<typename T, size_t D> Point<T,D> Zero();
    template<typename T, size_t D> Point<T,D> UnitPoint();

    template<typename T, size_t D> T AngleBetween(const Point<T,D>& lhs, const Point<T,D>& rhs);

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

} // namespace jl

#include "detail/Point.inl"
