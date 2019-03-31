#include "JumpGameII.h"
#include <cassert>

using namespace lcpp;

int Solution45_1::jump(std::vector<int> &nums) {
  std::vector<int>::size_type I, E = nums.size(), Step = 0, Farthest = 0,
                                 CurFarthest = 0;
  for (I = 0; I <= Farthest && I != E; ++I) {
    if (I > CurFarthest) {
      CurFarthest = Farthest;
      ++Step;
    }
    Farthest = std::max(Farthest, I + nums[I]);
  }
  assert(Farthest + 1 >= E && "can't reach the last index!");
  return Step;
}
