#include "SingleNumberII.h"
#include <cassert>

using namespace lcpp;

int Solution137_1::singleNumber(std::vector<int> &nums) {
  int LowBit = 0, HighBit = 0;
  for (const auto &N : nums) {
    LowBit = (LowBit ^ N) & ~HighBit;
    HighBit = (HighBit ^ N) & ~LowBit;
  }
  assert(HighBit == 0);
  return LowBit;
}
