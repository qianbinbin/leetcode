#include "PowXN.h"

using namespace lcpp;

double Solution50_1::myPow(double x, int n) {
  double Result = 1;
  for (unsigned N = n < 0 ? 0u - n : n; N != 0; N >>= 1) {
    if ((N & 1u) != 0)
      Result *= x;
    x *= x;
  }
  return n >= 0 ? Result : 1 / Result;
}
