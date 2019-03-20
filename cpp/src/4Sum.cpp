#include "4Sum.h"
#include <algorithm>

using namespace lcpp;

std::vector<std::vector<int>> Solution18_1::fourSum(std::vector<int> &nums,
                                                    int target) {
  std::vector<std::vector<int>> Result;
  if (nums.size() < 4)
    return Result;
  std::sort(nums.begin(), nums.end());
  for (auto I1 = nums.begin(), E1 = nums.end() - 3; I1 != E1;) {
    for (auto I2 = I1 + 1, E2 = nums.end() - 2; I2 != E2;) {
      auto Target = target - *I1 - *I2;
      auto I3 = I2 + 1, I4 = nums.end() - 1;
      while (I3 < I4) {
        auto Sum = *I3 + *I4;
        if (Sum < Target) {
          do {
            ++I3;
          } while (I3 != I4 && *I3 == *(I3 - 1));
        } else if (Sum > Target) {
          do {
            --I4;
          } while (I3 != I4 && *I4 == *(I4 + 1));
        } else {
          Result.push_back({*I1, *I2, *I3, *I4});
          do {
            ++I3;
          } while (I3 < I4 && *I3 == *(I3 - 1));
          do {
            --I4;
          } while (I3 < I4 && *I4 == *(I4 + 1));
        }
      }
      do {
        ++I2;
      } while (I2 != E2 && *I2 == *(I2 - 1));
    }
    do {
      ++I1;
    } while (I1 != E1 && *I1 == *(I1 - 1));
  }
  return Result;
}
