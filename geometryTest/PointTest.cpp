#include "geometry/Random.h"
#include "geometry/Point.h"

using namespace geom;

void TestVector()
{
    // Arithmetic operation test
    {
        auto reng = geom::MakeRandomEngine();
        auto p = geom::RandomPoint<double, 3>(reng, 0, 1);
        
    }
}