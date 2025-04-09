#include <iostream>
#include <cmath>

typedef float REAL;

int factorial(int n);
REAL fnaive(REAL x, int N);
REAL fsmart(REAL x, int N);

int main(void)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  REAL x = 1.234534534;
  const REAL exact = std::exp(-x);
  for (int NMAX = 0; NMAX <= 100; ++NMAX) {
    std::cout << NMAX
              << "\t" << fnaive(x, NMAX)
              << "\t" << std::fabs(fnaive(x, NMAX) - exact)/exact
              << "\t" << fsmart(x, NMAX)
              << "\t" << std::fabs(fsmart(x, NMAX) - exact)/exact
              << std::endl;
  }
  return 0;
}

REAL fnaive(REAL x, int N)
{
    REAL sum = 0.0;
    REAL term = 0.0;
    for (int ii = 0; ii < N; ii++)
    {
        term = std::pow(-x, ii)/factorial(ii); // Hago operaciones con numeros que crecen muy rapido
        sum += term;
    }
    return sum;
}
/*
Trato de realizar una operación recursiva para 
eliminar los factoriales

term(ii) = pow(-x, ii)/factorial(ii)
term(ii+1) = pow(-x, ii+1)/factorial(ii+1) = (-x)/(ii+1)*pow(-x, ii)/factorial(ii)=(-x)/(ii+1)*term(ii)
*/

int factorial(int n)
{
  if (n <= 0) return 1;
  return n*factorial(n-1);
}

REAL fsmart(REAL x, int N)
{
    REAL sum = 0.0, term = 1.0;
    for (int ii = 0; ii < N; ii++)
    {
        term *= (-x)/(ii+1);
        sum += term; 
    }
    return sum;
}