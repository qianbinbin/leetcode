#include "SearchInRotatedSortedArrayII.h"

using namespace lcpp;

bool Solution81_1::search(std::vector<int> &nums, int target) {
  int Low = 0, High = static_cast<int>(nums.size()) - 1, Mid;
  while (Low <= High) {
    Mid = Low + (High - Low) / 2;
    const auto &MidVal = nums[Mid];
    if (MidVal == target)
      return true;
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
      do {
        ++Low;
      } while (Low <= High && nums[Low] == LowVal);
    }
  }
  return false;
}
