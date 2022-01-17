#include "UniquePathsII.h"

using namespace lcpp;

int Solution63_1::uniquePathsWithObstacles(
    std::vector<std::vector<int>> &obstacleGrid) {
  const auto &M = obstacleGrid.size(), &N = obstacleGrid[0].size();
  std::vector<int> Dp(N);
  if (obstacleGrid[0][0] == 0)
    Dp[0] = 1;
  for (std::vector<int>::size_type J = 1;
       J != N && Dp[J - 1] == 1 && obstacleGrid[0][J] == 0; ++J)
    Dp[J] = 1;
  for (std::vector<std::vector<int>>::size_type I = 1; I != M; ++I) {
    const auto &Row = obstacleGrid[I];
    if (Dp[0] == 1 && Row[0] == 1)
      Dp[0] = 0;
    for (std::vector<int>::size_type J = 1; J != N; ++J) {
      if (Row[J] == 0)
        Dp[J] += Dp[J - 1];
      else
        Dp[J] = 0;
    }
  }
  return Dp[N - 1];
}
