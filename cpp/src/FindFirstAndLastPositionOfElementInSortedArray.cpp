#include "FindFirstAndLastPositionOfElementInSortedArray.h"
#include <cassert>
#include <limits>

using namespace lcpp;

std::vector<int> Solution34_1::searchRange(std::vector<int> &nums, int target) {
  assert(nums.size() <= std::numeric_limits<int>::max() && "Size overflow!");
  std::vector<int> Range{-1, -1};
  int Size = static_cast<int>(nums.size()), Low = 0, High = Size - 1, Mid;
  while (Low <= High) {
    Mid = Low + (High - Low) / 2;
    const auto &Value = nums[Mid];
    if (Value < target) {
      Low = Mid + 1;
    } else if (Value > target) {
      High = Mid - 1;
    } else {
      int I = Mid, J = Mid;
      while (I > 0 && nums[I - 1] == Value)
        --I;
      while (J < Size - 1 && nums[J + 1] == Value)
        ++J;
      Range[0] = I;
      Range[1] = J;
      break;
    }
  }
  return Range;
}
