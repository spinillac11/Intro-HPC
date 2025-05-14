#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);
void print_array(const double data[], const int & size);

int main (int argc, char **argv)
{
  int ii, jj;
  ii =  0;
  jj = -1;
  foo(ii, jj);
  foo(jj, ii);

  baz(25.9);

  const int NX = 2, NY = 3, NZ = 4;
  double *x; 
  //Declarar e inicializar arrays
  x = new double [NX]{0.0};
  double y[NY]{0.0}, z[NZ]{0.0}; // z - y en la memoria
  // primera impresión
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  
  // Llenar x
  for (int i = 0; i < NX; ++i) {
    x[i] = i*1.0;
  }

  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  
  // Llenar x, y y z 
  for (int i = 0; i < NX; ++i) {
    x[i] = (ii - NY)*1.0;
  }
  for (int j = 0; j < NY; ++j) {
    y[j] = (j - NZ)*1.0;
  }
  for (int k = 0; k < NZ; ++k) {
    z[k] = (NZ + NY)*1.0;
  }

  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  
  delete[] x; // Liberar memoria
  return EXIT_SUCCESS;
}

int foo(int a, int b)
{ 
  if(a == 0 || b == 0 || bar(a,b) == 0){
    std::cout << "Division por cero" << "\n"; 
    return 0;
  }else{
    return a/b + b/bar(a, b) + b/a;
  }
}

int bar(int a, int b)
{
  unsigned int c = 0;

  if(a < 0){
    c = -1*a;
  }else{
    c = a;
  }

  return c + a - b;
}

double baz(double x)
{
  if (x == 0) return 0;
  return std::sqrt(x);
}

void print_array(const double data[], const int & size)
{
  std::cout << std::endl;
  for (int ii = 0; ii < size; ++ii) {
    std::cout << data[ii] << "  ";
  }
  std::cout << std::endl;
}
