#include "MinimumPathSum.h"

using namespace lcpp;

int Solution64_1::minPathSum(std::vector<std::vector<int>> &grid) {
  const auto &N = grid[0].size();
  std::vector<int> Dp(N);
  Dp[0] = grid[0][0];
  for (std::vector<int>::size_type J = 1; J != N; ++J)
    Dp[J] = Dp[J - 1] + grid[0][J];
  for (auto I = grid.cbegin() + 1, E = grid.cend(); I != E; ++I) {
    const auto &Row = *I;
    Dp[0] += Row[0];
    for (std::vector<int>::size_type J = 1; J != N; ++J)
      Dp[J] = std::min(Dp[J - 1], Dp[J]) + Row[J];
  }
  return Dp[N - 1];
}
