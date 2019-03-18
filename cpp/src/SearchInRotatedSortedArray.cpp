#include "SearchInRotatedSortedArray.h"
#include <cassert>
#include <limits>

using namespace lcpp;

int Solution33_1::search(std::vector<int> &nums, int target) {
  assert(nums.size() <= std::numeric_limits<int>::max() && "Size overflow!");
  int Low = 0, High = static_cast<int>(nums.size()) - 1, Mid;
  while (Low <= High) {
    Mid = Low + (High - Low) / 2;
    const auto &MidVal = nums[Mid];
    if (MidVal == target)
      return Mid;
    const auto &LowVal = nums[Low];
    if (LowVal < MidVal) {
      if (LowVal <= target && target < MidVal)
        High = Mid - 1;
      else
        Low = Mid + 1;
    } else if (LowVal > MidVal) {
      if (MidVal < target && target <= nums[High])
        Low = Mid + 1;
      else
        High = Mid - 1;
    } else {
      Low = Mid + 1;
    }
  }
  return -1;
}
