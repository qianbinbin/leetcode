#include "SortColors.h"

using namespace lcpp;

void Solution75_1::sortColors(std::vector<int> &nums) {
  std::vector<int>::size_type Count0 = 0, Count1 = 0;
  for (auto &Num : nums) {
    switch (Num) {
    case 0:
      ++Count0;
      break;
    case 1:
      ++Count1;
      break;
    default:
      break;
    }
  }
  std::fill(nums.begin(), nums.begin() + Count0, 0);
  std::fill(nums.begin() + Count0, nums.begin() + Count0 + Count1, 1);
  std::fill(nums.begin() + Count0 + Count1, nums.end(), 2);
}

void Solution75_2::sortColors(std::vector<int> &nums) {
  auto Last0 = nums.begin() - 1, First2 = nums.end();
  for (auto I = nums.begin(); I != First2;) {
    if (*I == 0) {
      std::swap(*++Last0, *I++);
    } else if (*I == 2) {
      std::swap(*I, *--First2);
    } else {
      ++I;
    }
  }
}
