/*
Random.h
*/

#pragma once

#include "geometry/Point.h"

#include <random>
#include <cassert>

namespace geom
{
    /////////////////////// Random number generator

    inline std::mt19937 MakeRandomEngine(bool useRandomSeed = false)
    {
        // Will be used to obtain a seed for the random number engine
        if (useRandomSeed)
        {
            return std::mt19937(std::random_device()());
        }
        else
        {
            return std::mt19937();
        }
    }

    template<typename T>
    struct uniform_dist
    {
    };

    template<>
    struct uniform_dist<int> : std::uniform_int_distribution<int>
    {
        uniform_dist(int min, int max) : std::uniform_int_distribution<int>(min, max) {}
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
    Point<T, D> RandomPoint(RandomEng e, T min, T max)
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