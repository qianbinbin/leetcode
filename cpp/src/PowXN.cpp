#include "PowXN.h"

using namespace lcpp;

static double pow(double X, unsigned N) {
  if (N == 0)
    return 1.0;
  double Result = pow(X, N / 2);
  Result *= Result;
  if (N % 2 != 0)
    Result *= X;
  return Result;
}

double Solution50_1::myPow(double x, int n) {
  return n < 0 ? 1.0 / pow(x, 0u - n) : pow(x, n);
}

double Solution50_2::myPow(double x, int n) {
  double Result = 1;
  for (unsigned N = n < 0 ? 0u - n : n; N != 0; N >>= 1u) {
    if ((N & 1u) != 0)
      Result *= x;
    x *= x;
  }
  if (n < 0)
    Result = 1.0 / Result;
  return Result;
}
