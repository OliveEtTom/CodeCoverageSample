#include <iostream>
#include "src/BasicMath.h"

int main(int /*argc*/, char**/*argv*/)
{
    int a = 2, b = 3;
    int c = BasicMath::sum(a, b);
    std::cout << a << "+" << b << "=" << c << std::endl;
    int d = BasicMath::mul(a, b, true);
    std::cout << a << "*" << b << "=" << d << std::endl;
    return 0;
}