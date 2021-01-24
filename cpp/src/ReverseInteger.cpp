#include "ReverseInteger.h"

using namespace lcpp;

int Solution7_1::reverse(int x) {
  int Result = 0;
  for (; x != 0; x /= 10) {
    if (Result > 214748364 || Result < -214748364)
      return 0;
    Result = Result * 10 + x % 10;
  }
  return Result;
}
