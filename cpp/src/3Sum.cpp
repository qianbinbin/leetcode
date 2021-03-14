#include "3Sum.h"
#include <algorithm>

using namespace lcpp;

std::vector<std::vector<int>> Solution15_1::threeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> Set;
  if (nums.size() < 3)
    return Set;

  std::sort(nums.begin(), nums.end());
  std::vector<int>::iterator I, J, K, E;
  int Sum;
  for (I = nums.begin(), E = nums.end() - 2; I != E;) {
    Sum = 0 - *I;
    J = I + 1;
    K = E + 1;
    while (J < K) {
      if (*J + *K < Sum) {
        do {
          ++J;
        } while (J < K && *J == *(J - 1));
      } else if (*J + *K > Sum) {
        do {
          --K;
        } while (J < K && *K == *(K + 1));
      } else {
        Set.push_back({*I, *J, *K});
        do {
          ++J;
        } while (J < K && *J == *(J - 1));
        do {
          --K;
        } while (J < K && *K == *(K + 1));
      }
    }
    do {
      ++I;
    } while (I != E && *I == *(I - 1));
  }
  return Set;
}
