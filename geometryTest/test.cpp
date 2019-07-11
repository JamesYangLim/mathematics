#include "geometry/Vector.h"
//#include "geom/Vec.h"

#include <iostream>
#include <conio.h>

int main()
{
    geom::Vector<int, 3> v;
    geom::Vector<int, 3> v1(1, 2, 3);
    geom::Vector2<int> v2{ 1,2 };
    std::cout << v2.X() << " " << v2.Y() << "\n";

    std::cout << "Press a key...";
    _getch();
    return 0;
}