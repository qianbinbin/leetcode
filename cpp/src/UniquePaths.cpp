#include "UniquePaths.h"
#include <cstdint>
#include <vector>

int lcpp::Solution62_1::uniquePaths(int m, int n) {
  std::vector<int> Dp(n, 1);
  for (int I = 1, J; I < m; ++I) {
    for (J = 1; J < n; ++J) {
      Dp[J] += Dp[J - 1];
    }
  }
  return Dp[n - 1];
}

static int64_t factorial(int N, int K = 1) {
  int64_t Result = 1;
  for (; N >= K; --N)
    Result *= N;
  return Result;
}

static int64_t combination(int M, int N) {
  N = std::min(N, M - N);
  return factorial(M, M - N + 1) / factorial(N);
}

int lcpp::Solution62_2::uniquePaths(int m, int n) {
  return (int) combination(m + n - 2, m - 1);
}
