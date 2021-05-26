#include "MaximumSubarray.h"

using namespace lcpp;

int Solution53_1::maxSubArray(std::vector<int> &nums) {
  int Dp = -1, Result = std::numeric_limits<int>::min();
  for (auto &I : nums) {
    Dp = Dp < 0 ? I : Dp + I;
    Result = std::max(Result, Dp);
  }
  return Result;
}
