#include "Triangle.h"

using namespace lcpp;

int Solution120_1::minimumTotal(std::vector<std::vector<int>> &triangle) {
  const auto &N = triangle.size();
  std::vector<int> Dp = triangle[N - 1];
  for (std::vector<std::vector<int>>::size_type I = N - 2, IE = -1; I != IE;
       --I) {
    const auto &Row = triangle[I];
    for (std::vector<int>::size_type J = 0, JE = I + 1; J != JE; ++J)
      Dp[J] = std::min(Dp[J], Dp[J + 1]) + Row[J];
  }
  return Dp[0];
}
