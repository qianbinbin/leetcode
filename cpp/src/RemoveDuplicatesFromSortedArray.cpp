#include "RemoveDuplicatesFromSortedArray.h"

using namespace lcpp;

int Solution26_1::removeDuplicates(std::vector<int> &nums) {
  if (nums.empty())
    return 0;
  auto Last = nums.begin(), I = Last + 1, E = nums.end();
  for (; I != E; ++I) {
    if (*Last != *I) {
      *(++Last) = *I;
    }
  }
  return Last - nums.begin() + 1;
}
