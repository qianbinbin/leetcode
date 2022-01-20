#include "SqrtX.h"
#include <cassert>
#include <cstdint>

using namespace lcpp;

int Solution69_1::mySqrt(int x) {
  if (x < 2)
    return x;
  int64_t Low = 1, High = x / 2, Mid;
  while (Low <= High) {
    Mid = (Low + High) / 2;
    if (Mid * Mid > x) {
      High = Mid - 1;
    } else if ((Mid + 1) * (Mid + 1) <= x) {
      Low = Mid + 1;
    } else {
      return static_cast<int>(Mid);
    }
  }
  assert(false);
}

int Solution69_2::mySqrt(int x) {
  if (x < 2)
    return x;
  int64_t Result = x / 2;
  while (Result * Result > x || x >= (Result + 1) * (Result + 1))
    Result = (Result + x / Result) / 2;
  return static_cast<int>(Result);
}

int Solution69_3::mySqrt(int x) {
  int result = 0;
  int odd = 1;
  while (x >= odd) {
    x -= odd;
    ++result;
    odd += 2;
  }
  return result;
}
