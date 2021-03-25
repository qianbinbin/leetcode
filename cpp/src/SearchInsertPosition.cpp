#include "SearchInsertPosition.h"

using namespace lcpp;

int Solution35_1::searchInsert(std::vector<int> &nums, int target) {
  auto First = nums.begin(), Last = nums.end();
  while (First < Last) {
    auto I = First + (Last - First) / 2;
    if (*I < target)
      First = I + 1;
    else
      Last = I;
  }
  return First - nums.begin();
}
