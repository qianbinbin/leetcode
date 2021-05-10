#include "FirstMissingPositive.h"

using namespace lcpp;

int Solution41_1::firstMissingPositive(std::vector<int> &nums) {
  auto const &Size = nums.size();
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
