/*
InfiniteRegularGrid.h
*/

#pragma once

#include "JL/geometry/Point.h"
#include "JL/utils/Utils.h"

#include <ostream>

namespace jl
{
    template <typename T, size_t D> 
    struct InfiniteRegularGrid
    {
        Point<T, D> Origin;
        Point<T, D> Spacing;

        Point<T, D> GetPositionAtIndex(const Point<int32_t, D>& index);
    };

    template<typename T, size_t D> std::ostream& operator<<(std::ostream& os, const InfiniteRegularGrid<T, D>& g);

}

#include "detail/InfiniteRegularGrid.inl"
