#include "FirstMissingPositive.h"
#include <cassert>
#include <limits>

using namespace lcpp;

int Solution41_1::firstMissingPositive(std::vector<int> &nums) {
  const auto &Size = nums.size();
  assert(Size <= std::numeric_limits<int>::max());
  for (int I = 0, N; I != Size; ++I) {
    while ((N = nums[I]) != I + 1 && 0 < N && N <= Size && nums[N - 1] != N)
      std::swap(nums[I], nums[N - 1]);
  }
  for (int I = 0; I != Size; ++I) {
    if (nums[I] != I + 1)
      return I + 1;
  }
  return static_cast<int>(Size + 1);
}
