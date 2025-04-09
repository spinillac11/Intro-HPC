#include <cstdio>
#include <iostream>

int main(void)
{
    int a = 1;

    while (a > 0){
        a *= 2;
        std::cout << a << std::endl;
        std::cin.get(); // Debugguer basico: puedo ir paso por paso imprimiendo en la consola
    }
    return 0;
}