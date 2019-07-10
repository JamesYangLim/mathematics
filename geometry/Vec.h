#pragma once

#include <ostream>
#include <cassert>

#include <array>

namespace geom
{
	template <typename T, size_t D>
    struct Vec : std::array<T, D>
    {
        template <typename... Values>
		Vec(Values... values) : array({std::forward<Values>(values)...}) {}

		Vec& operator+=(const Vec& rhs)
		{
			for (size_t i = 0; i < size(); ++i)
			{
				(*this)[i] += rhs[i];
			}
			return *this;
		}

		Vec& operator-=(const Vec& rhs)
		{
			for (size_t i = 0; i < size(); ++i)
			{
				(*this)[i] -= rhs[i];
			}
			return *this;
		}
	};

    using Vec2i = Vec<int, 2>;
    using Vec2f = Vec<float, 2>;
    using Vec2d = Vec<double, 2>;

    using Vec3i = Vec<int, 3>;
    using Vec3f = Vec<float, 3>;
    using Vec3d = Vec<double, 3>;

    template <typename T, size_t D>
    std::ostream& operator<<(std::ostream& os, const Vec<T, D>& v) 
    {
        os << "Vec_";
        for (int i = 0; i < v.size(); ++i)
        {
            os << v[i];
            if (i < v.size() - 1)
            {
                os << ",";
            }
        }
        return os;
    }


    template <typename T, size_t D>
    Vec<T, D> operator+(const Vec<T, D>& lhs, const Vec<T, D>& rhs)
    {
		Vec<T, D> result = lhs;
		result += rhs;
		return result;
    }

    template <typename T, size_t D>
    Vec<T, D> operator-(const Vec<T, D>& lhs, const Vec<T, D>& rhs)
    {
		Vec<T, D> result = lhs;
		result -= rhs;
		return result;
	}


} // namespace geom