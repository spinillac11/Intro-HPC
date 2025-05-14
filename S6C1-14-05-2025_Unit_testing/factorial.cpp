#include "factorial.h"

long factorial(long number) //Long para disminuir el error debido a el crecimient rapido del factorial
{
    if (number == 0) return 1; 
    if (number < 0){
        std::cerr << "Valores negativos no aceptados";
        return -1; //Convención para pasar testing de números negativos
    }
    
    return number < 0 ? number : factorial(number-1)*number;
}
//Operador ternario condición ? caso verdadero : caso falso