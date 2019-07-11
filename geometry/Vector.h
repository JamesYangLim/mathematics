/*
Vector.h 
*/

#pragma once

#include <array>

namespace geom
{
    template <typename T, size_t Dimension>
    struct Vector
    {
        std::array<T, Dimension> v;

        template <typename... Values>
        Vector(Values... values) : v({ std::forward<Values>(values)... })
        {}

        friend std::ostream& operator<<(std::ostream& os, const Vector& v);
        friend Vector operator+(const Vector& rhs);
        Vector operator-(const Vector& rhs) const;
        Vector operator*(T v) const;
        Vector operator/(T v) const;
        Vector& operator+=(const Vector& rhs) const;
        Vector& operator-=(const Vector& rhs) const;
        Vector& operator*=(T rhs) const;
        Vector& operator/=(T rhs) const;
        Vector DotProduct(const Vector& rhs) const;
        Vector CrossProduct(const Vector& rhs) const;
    };

    template <typename T>
    struct Vector2 : Vector<T, 2>
    {
        Vector2(T x, T y) : Vector<T, 2>(x, y)
        {}

        T X() const { return this->v[0]; }
        T Y() const { return this->v[1]; };

    };

    template <typename T>
    struct Vector3 : Vector<T, 3>
    {
        Vector3(T x, T y, T z) : Vector<T, 3>(x, y, z)
        {}

        T X() const { return this->v[0]; }
        T Y() const { return this->v[1]; };
        T Z() const { return this->v[2]; };

    };

}