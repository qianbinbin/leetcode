#include "SortColors.h"

using namespace lcpp;

void Solution75_1::sortColors(std::vector<int> &nums) {
  std::vector<int>::size_type Count0 = 0, Count1 = 0;
  for (auto &Num : nums) {
    switch (Num) {
    case 0:++Count0;
      break;
    case 1:++Count1;
      break;
    default:break;
    }
  }
  std::vector<int>::size_type I = 0;
  for (; I != Count0; ++I)
    nums[I] = 0;
  for (const auto E = Count0 + Count1; I != E; ++I)
    nums[I] = 1;
  for (const auto &E = nums.size(); I != E; ++I)
    nums[I] = 2;
}
