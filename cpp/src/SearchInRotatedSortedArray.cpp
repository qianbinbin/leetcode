#include "SearchInRotatedSortedArray.h"

using namespace lcpp;

int Solution33_1::search(std::vector<int> &nums, int target) {
  auto Low = nums.begin(), High = nums.end() - 1;
  while (Low <= High) {
    auto Mid = Low + (High - Low) / 2;
    if (*Mid == target)
      return Mid - nums.begin();
    if (*Low <= *Mid) {
      if (*Low <= target && target < *Mid)
        High = Mid - 1;
      else
        Low = Mid + 1;
    } else {
      if (*Mid < target && target <= *High)
        Low = Mid + 1;
      else
        High = Mid - 1;
    }
  }
  return -1;
}
