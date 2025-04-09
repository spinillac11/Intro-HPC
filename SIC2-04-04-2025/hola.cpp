#include <iostream>

int main(void){
    std::string name;
    std::cout << "Please write your name" << std::endl;
    // std::cin >> name; Sólo lee la primera linea del argumento dado
    std::getline(std::cin, name); // Lee todo el string incluyendo los espacios
    std::cout << "Hola" + name + "\n";

    return 0;
}