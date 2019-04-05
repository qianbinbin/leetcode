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
  assert(m > 0 && n > 0);
  return combination(m + n - 2, m - 1);
}
