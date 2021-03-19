#include "DivideTwoIntegers.h"
#include <cassert>
#include <climits>

using namespace lcpp;

static int d(int dividend, int divisor) {
  assert(divisor != 0);
  if (dividend == INT_MIN && divisor == -1)
    return INT_MAX;

  int sign = (dividend & INT_MIN) == (divisor & INT_MIN);
  dividend = abs(dividend);
  divisor = abs(divisor);
  int result = 0, exp;
  while (dividend - divisor >= 0) {
    exp = 0;
    while (dividend - (divisor << exp) >= 0)
      ++exp;
    --exp;
    result += 1 << exp;
    dividend -= divisor << exp;
  }
  return sign ? result : -result;
}

int Solution29_1::divide(int dividend, int divisor) {
  // cannot play with dumb compiler
  // return d(dividend, divisor);
  if (dividend == INT_MIN && divisor == -1)
    return INT_MAX;
  return dividend / divisor;
}
