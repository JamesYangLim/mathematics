/*
PlyTest.cpp
*/

#include "JL/geometry/Random.h"
#include "JL/geometry/Point.h"
#include "JL/geometry/Ply.h"

#include <iostream>
#include <vector>

using namespace jl;

void TestPly()
{
	using T = float;
	const size_t D = 3;

	std::vector<Point<T, D>> points;

	auto rn = GetRandomEngine();

	for (size_t i = 0; i < 1000; ++i)
	{
		points.push_back(RandomPoint<T, D>(rn, -10, 10));
	}

	WritePointsToPlyFile(points, "test");
}