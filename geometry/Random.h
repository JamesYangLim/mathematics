/*
Random.h
*/

#pragma once

#include "geometry/Point.h"

#include <random>
#include <cassert>

namespace geom
{
    // std::random_device()

    /////////////////////// Random number generator

    inline std::mt19937 GetRandomEngine(uint32_t seed = 5489U)
    {
        return std::mt19937(seed);
    }

    template<typename T>
    struct uniform_dist {};

    template<>
    struct uniform_dist<int32_t> : std::uniform_int_distribution<int32_t>
    {
        uniform_dist(int32_t min, int32_t max) : std::uniform_int_distribution<int32_t>(min, max) {}
    };

    template<>
    struct uniform_dist<float> : std::uniform_real_distribution<float>
    {
        uniform_dist(float min, float max) : std::uniform_real_distribution<float>(min, max) {}
    };

    template<>
    struct uniform_dist<double> : std::uniform_real_distribution<double>
    {
        uniform_dist(double min, double max) : std::uniform_real_distribution<double>(min, max) {}
    };

    /////////////////////// Random point generator

    template<typename T, size_t D, typename RandomEng>
    Point<T, D> RandomPoint(RandomEng& e, T min, T max)
    {
        assert(max >= min);
        uniform_dist<T> rng(min, max);
        std::array<T, D> v;
        for (size_t i = 0; i < D; ++i)
        {
            v[i] = rng(e);
        }
        return Point<T, D>{v};
    }

} // namespace geom