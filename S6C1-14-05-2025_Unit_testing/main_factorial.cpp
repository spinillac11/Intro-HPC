#include <iostream>
#include "factorial.h"

int main(void)
{
    std::cout << factorial(0.5) << std::endl;
    std::cout << factorial(2) << std::endl;
    std::cout << factorial(16) << std::endl;
    std::cout << factorial(-4) << std::endl;
    return 0;
}
