#include <iostream>
#include <fstream>
#include <cmath>

typedef float REAL; // FLoat tiene e7 cifras representativas

// Function declaration  
REAL sumup (int N);
REAL sumdw (int N);

int main(void){
    int Nmax = 1.01e6;
    int step = 10000; // Imprimir cada paso
    REAL delta = 0.0;
    REAL SumUP = 0.0;
    REAL SumDW = 0.0;

    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);
    std::ofstream outfile("data.txt");

    for(int N = 1; N <= Nmax; N += step){
        SumUP = sumup(N);
        SumDW = sumdw(N);
        delta = std::fabs(SumDW - SumUP)/SumDW;
        outfile << N << " " << SumUP  << " " << SumDW << " " << delta << "\n";
    }
    outfile.close();

    return 0;
}

REAL sumup (int N){

    REAL suma = 0.0;

    for (int k = 1; k <= N; k++){
        suma += 1.0 / (k);
    }

    return suma; 
}

REAL sumdw (int N){

    REAL suma = 0.0;

    for (int k = N; k >= 1; k--){
        suma += 1.0 / k;
    }

    return suma; 
}