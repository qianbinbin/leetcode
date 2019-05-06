#include "SlidingWindowMaximum.h"
#include <cassert>

using namespace lcpp;

std::vector<int> Solution239_1::maxSlidingWindow(std::vector<int> &nums,
                                                 int k) {
  const auto &Size = nums.size();
  if (Size == 0)
    return std::vector<int>(0);
  assert(1 <= k && k <= Size);
  std::vector<int> Left(Size, nums[0]), Right(Size, nums[Size - 1]), Result;
  Result.reserve(Size - k + 1);
  std::vector<int>::size_type I;
  for (I = 1; I != Size; ++I)
    Left[I] = I % k == 0 ? nums[I] : std::max(nums[I], Left[I - 1]);
  for (I = Size - 2; I != -1; --I)
    Right[I] = (I + 1) % k == 0 ? nums[I] : std::max(nums[I], Right[I + 1]);
  for (I = k - 1; I != Size; ++I)
    Result.push_back(std::max(Left[I], Right[I - k + 1]));
  return Result;
}
