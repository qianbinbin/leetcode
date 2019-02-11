#include "RemoveElement.h"
#include <cassert>
#include <limits>

using namespace lcpp;

int Solution27_1::removeElement(std::vector<int> &nums, int val) {
  assert(nums.size() <= std::numeric_limits<int>::max()
             && "Vector size overflow!");
  int Size = 0;
  for (const auto &N : nums) {
    if (N != val)
      nums[Size++] = N;
  }
  return Size;
}
