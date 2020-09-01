/*
InfiniteRegularGrid.inl
*/

#pragma once

#include "JL/utils/Utils.h"

namespace jl
{
	template<typename T, size_t D> 
	std::ostream& operator<<(std::ostream& os, const InfiniteRegularGrid<T, D>& g)
	{
		os << "Origin: " << g.Origin << " Spacing: " << g.Spacing << "\n";
		return os;
	}


	template <typename T, size_t D> 
	Point<T, D> InfiniteRegularGrid<T, D>::GetPositionAtIndex(const Point<int32_t, D>& index)
	{
		return ComponentMultiply((Origin + Spacing), index);
	}
}