#include <iostream>
#include <cmath>

typedef float REAL; // FLoat tiene e7 cifras representativas

// Function declaration  
REAL sumN1 (int N);
REAL sumN2 (int N);
REAL sumN3 (int N);


int main(void){
    int Nmax = 1000;

    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    for(int N = 1; N <= Nmax; N++){
        std::cout << N << " " << sumN1(N) 
                        << " " << sumN2(N) 
                        << " " << sumN3(N) 
                        << std::endl;
    }
     
    return 0;
}

REAL sumN1 (int N){

    REAL sum = 0.0;
    for (int n = 1; n <= 2*N; n++)
    { 
        sum += std::pow(-1,n) * 1.0 * n/(n+1); 
    }
    return sum;
}

REAL sumN2 (int N){

    REAL suma_pos = 0.0;
    REAL suma_neg = 0.0;
    REAL n2;
    
    for (int n = 1; n <= N; n++)
    {
        n2 = 2.0*n;

        suma_pos += n2 / (n2 + 1.0);
        suma_neg += (n2 - 1.0) / n2 ;
    }
    return suma_pos - suma_neg;
}

REAL sumN3 (int N)
{
    REAL sum = 0.0;
    REAL aux = 0.0;
    for(int n = 1; n <= N; n++) {
        aux = 1/(2*n*(2*n+1)*1.0);
        sum += aux;
    }
    return sum;
}