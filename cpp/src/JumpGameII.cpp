#include "JumpGameII.h"

using namespace lcpp;

int Solution45_1::jump(std::vector<int> &nums) {
  std::vector<int>::size_type I, E = nums.size(), Farthest = 0,
                                 LastFarthest = 0;
  int Step = 0;
  for (I = 0; I <= Farthest && I != E; ++I) {
    if (I > LastFarthest) {
      LastFarthest = Farthest;
      ++Step;
    }
    Farthest = std::max(Farthest, I + nums[I]);
  }
  return Step;
}
