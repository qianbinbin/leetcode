#include "NextPermutation.h"
#include <algorithm>

using namespace lcpp;

void Solution31_1::nextPermutation(std::vector<int> &nums) {
  auto RI = nums.rbegin() + 1, RE = nums.rend();
  while (RI != RE && *RI >= *(RI - 1))
    ++RI;
  if (RI != RE) {
    auto RJ = nums.rbegin();
    while (RJ != RI && *RJ <= *RI)
      ++RJ;
    std::swap(*RI, *RJ);
  }
  std::reverse(RI.base(), nums.end());
}
