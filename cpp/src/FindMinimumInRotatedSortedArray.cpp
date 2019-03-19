#include "FindMinimumInRotatedSortedArray.h"
#include <cassert>
#include <limits>

using namespace lcpp;

int Solution153_1::findMin(std::vector<int> &nums) {
  const auto &Size = nums.size();
  assert(Size > 0 && "nums can't be empty!");
  assert(Size <= std::numeric_limits<int>::max() && "Size overflow!");
  int Low = 0, High = static_cast<int>(Size) - 1, Mid;
  while (Low < High && nums[Low] > nums[High]) {
    Mid = Low + (High - Low) / 2;
    if (nums[Mid] > nums[High])
      Low = Mid + 1;
    else
      High = Mid;
  }
  return nums[Low];
}
