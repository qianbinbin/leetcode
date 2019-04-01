#include "RegularExpressionMatching.h"
#include <vector>

using namespace lcpp;

bool Solution10_1::isMatch(std::string s, std::string p) {
  const auto &M = s.size(), &N = p.size();
  if (N == 0)
    return M == 0;
  std::vector<std::vector<bool>> Dp(M + 1, std::vector<bool>(N + 1));
  Dp[0][0] = true;
  for (std::string::size_type J = 2, E = N + N % 2 + 2;
       J != E && Dp[0][J - 2] && p[J - 1] == '*'; J += 2)
    Dp[0][J] = true;
  if (M != 0 && (p[0] == '.' || p[0] == s[0]))
    Dp[1][1] = true;
  for (std::string::size_type I = 1, IE = M + 1; I != IE; ++I) {
    for (std::string::size_type J = 2, JE = N + 1; J != JE; ++J) {
      const auto &chS = s[I - 1], &chP = p[J - 1];
      if (chP == '*') {
        if (Dp[I][J - 2])
          Dp[I][J] = true;
        else if ((p[J - 2] == '.' || p[J - 2] == s[I - 1]) && Dp[I - 1][J]) {
          Dp[I][J] = true;
        }
      } else if ((chP == '.' || chP == chS) && Dp[I - 1][J - 1]) {
        Dp[I][J] = true;
      }
    }
  }
  return Dp[M][N];
}
