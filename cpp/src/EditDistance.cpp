#include "EditDistance.h"
#include <vector>

using namespace lcpp;

int Solution72_1::minDistance(std::string word1, std::string word2) {
  const auto &M = word1.size(), &N = word2.size();
  std::vector<std::vector<int>> Dp(M + 1, std::vector<int>(N + 1));
  for (std::string::size_type J = 0; J <= N; ++J)
    Dp[0][J] = J;
  for (std::string::size_type I = 1; I <= M; ++I) {
    Dp[I][0] = I;
    for (std::string::size_type J = 1; J <= N; ++J) {
      if (word1[I - 1] == word2[J - 1])
        Dp[I][J] = Dp[I - 1][J - 1];
      else
        Dp[I][J] =
            std::min(Dp[I - 1][J - 1], std::min(Dp[I - 1][J], Dp[I][J - 1])) +
            1;
    }
  }
  return Dp[M][N];
}
