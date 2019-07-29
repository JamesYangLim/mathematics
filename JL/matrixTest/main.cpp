/*
main.cpp
*/

#include <iostream>
#include <conio.h>

void TestMatrix();
void TestTransformation();

int main()
{
    TestMatrix();
    TestTransformation();

    std::cout << "Press a key...";
    _getch();
    return 0;
}