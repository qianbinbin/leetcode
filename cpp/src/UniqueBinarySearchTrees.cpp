#include "UniqueBinarySearchTrees.h"
#include <vector>

using namespace lcpp;

int Solution96_1::numTrees(int n) {
  // assert(n > 0);
  if (n < 2)
    return 1;
  typedef std::vector<int>::size_type SizeType;
  std::vector<int> Dp(static_cast<SizeType>(n + 1));
  Dp[0] = 1;
  Dp[1] = 1;
  for (SizeType I = 2; I <= n; ++I) {
    for (SizeType Left = 0; Left != I; ++Left)
      Dp[I] += Dp[Left] * Dp[I - Left - 1];
  }
  return Dp[n];
}
