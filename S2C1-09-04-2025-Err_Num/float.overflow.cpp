#include <iostream>
#include <cstdlib>

// typedef float REAL;
typedef double REAL; 

int main(int argc, char **argv){
    std::cout.precision(16); // Precision
    std::cout.setf(std::ios::scientific); // NOtacion cientifica
    int N = std::atoi(argv[1]);
    REAL under = 1.0, over = 1.0;

    for(int ii = 1; ii <= N ; ii++){

        under /= 2;
        over *= 2;
        std::cout << ii << " " << under << " " << over << std::endl;
    }
    return 0;
}