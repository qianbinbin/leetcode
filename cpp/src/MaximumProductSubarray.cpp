#include "MaximumProductSubarray.h"
#include <cassert>

using namespace lcpp;

int Solution152_1::maxProduct(std::vector<int> &nums) {
  assert(!nums.empty());
  int Result = nums[0], Max = Result, Min = Result;
  for (auto I = nums.cbegin() + 1, E = nums.cend(); I != E; ++I) {
    auto &N = *I;
    if (N < 0)
      std::swap(Max, Min);
    Max = std::max(N, N * Max);
    Min = std::min(N, N * Min);
    if (Max > Result)
      Result = Max;
  }
  return Result;
}
