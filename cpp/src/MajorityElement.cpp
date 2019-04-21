#include "MajorityElement.h"
#include <cassert>

using namespace lcpp;

int Solution169_1::majorityElement(std::vector<int> &nums) {
  assert(!nums.empty());
  int Value = nums[0];
  std::vector<int>::size_type Count = 1;
  for (auto I = nums.cbegin() + 1, E = nums.cend(); I != E; ++I) {
    if (*I == Value) {
      ++Count;
    } else if (Count > 0) {
      --Count;
    } else {
      Value = *I;
      Count = 1;
    }
  }
  assert(Count > 0);
  return Value;
}
