#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
  // declare variables
  const int N = 10;
  double * array;
  //reserve memory
  array = new double [N];
  // initialise array
  for (int ii = 0; ii < N; ++ii) {
    array[ii] = 2*(++ii); // != 2*(ii++) ?
  }
  // print some values
  int idx = 2;
  std::cout << array[idx] << std::endl;
  idx = 10;
  //std::cout << array[idx] << std::endl; // compiles, but ...

  // free memory
  delete [] array; // Hay que liberar la memoria std::vector lo hace automaticamente

  return EXIT_SUCCESS;
}
/*
    Compilar con g++ -g -fsanitize=address,leak,undefined para buscar fugas de memoria y/o números indefinidos 
    -g para ejecutar con simbilos de debuggin
*/