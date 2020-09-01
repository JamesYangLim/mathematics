/*
InfiniteRegularGridTest.cpp
*/

#include "JL/geometry/InfiniteRegularGrid.h"
#include "JL/geometry/Random.h"

#include <iostream>

using namespace jl;

void TestInifiniteRegularGrid()
{
	std::cout << "##### Inifinite Regular Grid Test #####\n";

	using T = int32_t;
	const size_t D = 2;
	const T min = -10;
	const T max = 10;

	uniform_dist<T> rnInt32(min, max);
	auto reng = GetRandomEngine();

	{
		std::cout << "Test 1: Get position from grid index test\n";

		for (size_t i = 0; i < 10; ++i)
		{
			auto origin = RandomPoint<T, D>(reng, min, max);
			auto spacing = RandomPoint<T, D>(reng, 1, max);

			InfiniteRegularGrid<T, D> grid{ origin, spacing };

			for (size_t j = 0; j < 1000; ++j)
			{
				auto gridIndex = RandomPoint<T, D>(reng, min, max);
				auto pos = grid.GetPositionAtIndex(gridIndex);
				//ALWAYS_ASSERT(pos == gridIndex);
			}
		}

	}
}