/*
Vector.h 
*/

#pragma once

#include <array>

namespace geom
{
    template <typename T, size_t Dimension>
    struct Vector : std::array<T, Dimension>
    {
        template <typename... Values>
        Vector(Values... values) : array({ std::forward<Values>(values)... })
        {}

        friend std::ostream& operator<<(std::ostream& os, const Vector& v);
        Vector operator+(const Vector& rhs) const;
        Vector operator-(const Vector& rhs) const;
        Vector operator*(T v) const;
        Vector operator/(T v) const;
        Vector DotProduct(const Vector& rhs) const;
        Vector CrossProduct(const Vector& rhs) const;
    };



}