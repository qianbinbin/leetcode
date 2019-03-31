#include "JumpGame.h"

using namespace lcpp;

bool Solution55_1::canJump(std::vector<int> &nums) {
  std::vector<int>::size_type I, E = nums.size(), Farthest = 0;
  for (I = 0; I <= Farthest && Farthest + 1 < E; ++I)
    Farthest = std::max(Farthest, I + nums[I]);
  return Farthest + 1 >= E;
}
