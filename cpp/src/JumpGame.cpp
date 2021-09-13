#include "JumpGame.h"

using namespace lcpp;

bool Solution55_1::canJump(std::vector<int> &nums) {
  std::vector<int>::size_type I, Farthest, E = nums.size();
  for (I = 0, Farthest = 0; I <= Farthest && Farthest + 1 < E; ++I)
    Farthest = std::max(Farthest, I + nums[I]);
  return Farthest + 1 >= E;
}

bool Solution55_2::canJump(std::vector<int> &nums) {
  std::vector<int>::size_type I, E = nums.size();
  int Remainder = 0;
  for (I = 0; I != E && Remainder >= 0; ++I)
    Remainder = std::max(Remainder, nums[I]) - 1;
  return I == E;
}
