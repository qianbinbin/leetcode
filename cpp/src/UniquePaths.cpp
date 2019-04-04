#include "UniquePaths.h"
#include <cassert>
#include <vector>

int lcpp::Solution62_1::uniquePaths(int m, int n) {
  assert(m > 0 && n > 0);
  const int M = n, N = m;
  std::vector<int> Dp(N, 1);
  for (int I = 1; I != M; ++I) {
    for (int J = 1; J != N; ++J) {
      Dp[J] += Dp[J - 1];
    }
  }
  return Dp[N - 1];
}
