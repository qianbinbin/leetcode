#include "ClimbingStairs.h"
#include <cassert>
#include <limits>

using namespace lcpp;

int Solution70_1::climbStairs(int n) {
  assert(n > 0 && n != std::numeric_limits<int>::max());
  int Pre = 1, Dp = 1;
  for (int I = 2; I <= n; ++I) {
    Pre += Dp;
    std::swap(Pre, Dp);
  }
  return Dp;
}
