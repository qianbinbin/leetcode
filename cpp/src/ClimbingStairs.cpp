#include "ClimbingStairs.h"

using namespace lcpp;

int Solution70_1::climbStairs(int n) {
  int PrePre = 1, Pre = 1, Result = 1;
  for (int I = 2; I <= n; ++I) {
    Result = PrePre + Pre;
    PrePre = Pre;
    Pre = Result;
  }
  return Result;
}
