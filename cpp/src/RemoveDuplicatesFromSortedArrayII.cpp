#include "RemoveDuplicatesFromSortedArrayII.h"

using namespace lcpp;

int Solution80_1::removeDuplicates(std::vector<int> &nums) {
  auto Size = nums.size();
  if (Size < 3)
    return static_cast<int>(Size);
  Size = 2;
  for (auto I = nums.begin() + 2, E = nums.end(); I != E; ++I) {
    if (*I != nums[Size - 2])
      nums[Size++] = *I;
  }
  return static_cast<int>(Size);
}
