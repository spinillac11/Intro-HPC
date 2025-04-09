#include <iostream>
#include <cstdlib>

typedef double REAL; 

int main(int argc, char **argv){
    std::cout.precision(16); // Precision
    std::cout.setf(std::ios::scientific); // NOtacion cientifica
    int N = std::atoi(argv[1]);
    
    REAL eps = 1.0;
    REAL one = 1.0;

    for(int ii = 1; ii <= N ; ii++){
        one = 1.0 + eps;
        std::cout << ii << " " << eps << " " << one << std::endl;

        eps /= 2;
    }
    return 0;
}