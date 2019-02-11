#include "RemoveDuplicatesFromSortedArray.h"
#include <cassert>

using namespace lcpp;

int Solution26_1::removeDuplicates(std::vector<int> &nums) {
  const int Size = static_cast<const int>(nums.size());
  assert(Size >= 0 && "Vector size overflow!");
  if (Size < 2)
    return Size;
  int Index = 0;
  for (auto I = nums.begin() + 1, E = nums.end(); I != E; ++I) {
    if (*I != nums[Index])
      nums[++Index] = *I;
  }
  return Index + 1;
}
