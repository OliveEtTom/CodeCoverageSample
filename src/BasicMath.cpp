#include "BasicMath.h"
#include <iostream>

int BasicMath::sum(int a, int b, bool log)
{
    if (log)
    {
        std::cout << "sum(" << a << ", " << b << ")" << std::endl;
    }
    return a + b;
}


int BasicMath::mul(int a, int b, bool log)
{
    if (log)
    {
        std::cout << "mul(" << a << ", " << b << ")" << std::endl;
    }
    return a * b;
}