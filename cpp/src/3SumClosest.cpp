#include "3SumClosest.h"
#include <algorithm>

using namespace lcpp;

int Solution16_1::threeSumClosest(std::vector<int> &nums, int target) {
  std::sort(nums.begin(), nums.end());
  std::vector<int>::iterator I, J, K, E;
  int Sum, Closest = nums[0] + nums[1] + nums[2];
  for (I = nums.begin(), E = nums.end() - 2; I != E;) {
    J = I + 1;
    K = E + 1;
    while (J != K) {
      Sum = *I + *J + *K;
      if (std::abs(Sum - target) < std::abs(Closest - target))
        Closest = Sum;
      if (Sum < target) {
        do {
          ++J;
        } while (J != K && *J == *(J - 1));
      } else if (Sum > target) {
        do {
          --K;
        } while (J != K && *K == *(K + 1));
      } else {
        return target;
      }
    }
    do {
      ++I;
    } while (I != E && *I == *(I - 1));
  }
  return Closest;
}
