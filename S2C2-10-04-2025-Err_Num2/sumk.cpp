#include <iostream>
#include <cmath>

typedef float REAL; // FLoat tiene e7 cifras representativas

// Function declaration  
REAL sumk (int k);


int main(void){
    int kmax = 1000;

    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    for(int k = 1; k <= kmax; k++){
        std::cout << k << " " << sumk(k) << std::endl;
    }
     
    return 0;
}

REAL sumk (int k){

    REAL suma = 0.0;

    for (int ii = 1; ii <= k; ii++){
        suma += 0.1;
    }

    REAL aux = k/10.0; // Cómo k es un entero k/10 se trunca a cero -> k/10.0 (float)
    return std::fabs(aux - suma); 
}