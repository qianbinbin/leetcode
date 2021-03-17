#include "RemoveElement.h"

using namespace lcpp;

int Solution27_1::removeElement(std::vector<int> &nums, int val) {
  auto I = nums.begin();
  for (auto const &N : nums) {
    if (N != val)
      *I++ = N;
  }
  return I - nums.begin();
}
