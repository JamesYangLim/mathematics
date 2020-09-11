/*
Ply.h
*/

#pragma once

#include "Libs/tinyply/tinyply.h"
#include "JL/geometry/Point.h"

#include <fstream>
#include <vector>
#include <algorithm>

using namespace tinyply;

namespace jl
{
	template<typename T>
	void WritePoint3ToPlyFile(const std::vector<Point<T, 3>>& points, const std::string& filename);
}

#include "detail/Ply.inl"