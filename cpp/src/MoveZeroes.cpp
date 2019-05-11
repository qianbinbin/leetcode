#include "MoveZeroes.h"

using namespace lcpp;

void Solution283_1::moveZeroes(std::vector<int> &nums) {
  auto I = nums.begin(), J = I, E = nums.end();
  for (; J != E; ++J) {
    if (*J == 0)
      continue;
    *I++ = *J;
  }
  std::fill(I, E, 0);
}
