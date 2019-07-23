/*
MatrixTest.cpp
*/

#include "JL/matrix/Matrix.h"

#include <iostream>

using namespace jl;

void TestMatrix()
{
    {
        auto A = IdentityMatrix<int, 3, 3>();
        std::cout << A << "\n";
    }
}