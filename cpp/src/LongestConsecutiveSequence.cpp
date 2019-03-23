#include "LongestConsecutiveSequence.h"
#include <unordered_set>

using namespace lcpp;

int Solution128_1::longestConsecutive(std::vector<int> &nums) {
  int Longest = 0, I;
  std::unordered_set<int> Set(nums.begin(), nums.end());
  const auto &E = Set.cend();
  for (const auto &N : nums) {
    if (Set.find(N - 1) == E) {
      for (I = N + 1; Set.find(I) != E; ++I);
      Longest = std::max(Longest, I - N);
    }
  }
  return Longest;
}
