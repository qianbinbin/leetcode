#include "HouseRobber.h"

using namespace lcpp;

int Solution198_1::rob(std::vector<int> &nums) {
  int DP0 = 0, DP1 = 0, Tmp;
  for (const auto &N : nums) {
    Tmp = DP0;
    DP0 = std::max(DP0, DP1);
    DP1 = Tmp + N;
  }
  return std::max(DP0, DP1);
}
