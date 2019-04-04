#include "MaximumSubarray.h"
#include <cassert>

using namespace lcpp;

int Solution53_1::maxSubArray(std::vector<int> &nums) {
  assert(!nums.empty());
  int Dp = nums[0], Max = Dp;
  for (auto I = nums.cbegin() + 1, E = nums.cend(); I != E; ++I) {
    Dp = (Dp > 0 ? Dp : 0) + *I;
    if (Dp > Max)
      Max = Dp;
  }
  return Max;
}
