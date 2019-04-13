#include "DivideTwoIntegers.h"
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <limits>

using namespace lcpp;

int Solution29_1::divide(int dividend, int divisor) {
  assert(divisor != 0);
  int SignBit = (static_cast<unsigned>(dividend) & 0x80000000) ^
                (static_cast<unsigned>(divisor) & 0x80000000);
  int64_t Result = 0, Count, Sub,
          Dividend = std::abs(static_cast<int64_t>(dividend)),
          Divisor = std::abs(static_cast<int64_t>(divisor));
  while (Dividend >= Divisor) {
    Count = 1;
    Sub = Divisor;
    while (Dividend >= Sub) {
      Count *= 2;
      Sub *= 2;
    }
    Dividend -= Sub / 2;
    Result += Count / 2;
  }
  if (SignBit != 0)
    Result *= -1;
  if (Result > std::numeric_limits<int>::max())
    return std::numeric_limits<int>::max();
  if (Result < std::numeric_limits<int>::min())
    return std::numeric_limits<int>::min();
  return Result;
}
