#include "FindFirstAndLastPositionOfElementInSortedArray.h"

using namespace lcpp;

static std::vector<int>::iterator binarySearch(std::vector<int>::iterator First,
                                               std::vector<int>::iterator Last,
                                               int Val, bool Lower) {
  while (First < Last) {
    auto Mid = First + (Last - First) / 2;
    if (Val < *Mid || (Lower && Val == *Mid))
      Last = Mid;
    else
      First = Mid + 1;
  }
  return First;
}

std::vector<int> Solution34_1::searchRange(std::vector<int> &nums, int target) {
  auto I = binarySearch(nums.begin(), nums.end(), target, true);
  if (I == nums.end() || *I != target)
    return {-1, -1};
  return {static_cast<int>(I - nums.begin()),
          static_cast<int>(binarySearch(I, nums.end(), target, false) -
                           nums.begin() - 1)};
}
