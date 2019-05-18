#include "LongestIncreasingSubsequence.h"

using namespace lcpp;

int Solution300_1::lengthOfLIS(std::vector<int> &nums) {
  if (nums.empty())
    return 0;
  std::vector<std::vector<int>::size_type> DP(nums.size(), 1);
  std::vector<int>::size_type Len = 1;
  for (std::vector<int>::size_type I = 1, J, E = nums.size(), L; I != E; ++I) {
    for (J = 0, L = 1; J != I; ++J) {
      if (nums[J] < nums[I])
        L = std::max(L, DP[J] + 1);
    }
    DP[I] = L;
    Len = std::max(Len, L);
  }
  return Len;
}
