#include "DistinctSubsequences.h"
#include <vector>

using namespace lcpp;

int Solution115_1::numDistinct(std::string s, std::string t) {
  if (s.size() < t.size())
    return 0;
  const auto M = s.size() + 1, N = t.size() + 1;
  std::vector<std::vector<int>> Dp(M, std::vector<int>(N));
  Dp[0][0] = 1;
  std::string::size_type I, J, JE;
  for (I = 1; I != M; ++I) {
    Dp[I][0] = 1;
    for (J = 1, JE = std::min(N, I + 1); J != JE; ++J) {
      if (s[I - 1] == t[J - 1])
        Dp[I][J] = Dp[I - 1][J] + Dp[I - 1][J - 1];
      else
        Dp[I][J] = Dp[I - 1][J];
    }
  }
  return Dp[M - 1][N - 1];
}
