#include "SingleNumberII.h"

using namespace lcpp;

int Solution137_1::singleNumber(std::vector<int> &nums) {
  int One = 0, Two = 0;
  for (const auto &N : nums) {
    One = (One ^ N) & ~Two;
    Two = (Two ^ N) & ~One;
  }
  return One;
}
