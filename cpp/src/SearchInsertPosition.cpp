#include "SearchInsertPosition.h"
#include <cassert>
#include <limits>

using namespace lcpp;

int Solution35_1::searchInsert(std::vector<int> &nums, int target) {
  assert(nums.size() <= std::numeric_limits<int>::max() && "Size overflow!");
  int Low = 0, High = static_cast<int>(nums.size()) - 1, Mid;
  while (Low <= High) {
    Mid = Low + (High - Low) / 2;
    const auto &Value = nums[Mid];
    if (Value < target) {
      Low = Mid + 1;
    } else if (Value > target) {
      High = Mid - 1;
    } else {
      return Mid;
    }
  }
  return Low;
}
