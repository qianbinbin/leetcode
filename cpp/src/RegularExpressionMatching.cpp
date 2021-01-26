#include "RegularExpressionMatching.h"
#include <vector>

using namespace lcpp;

static bool match(const char *S, const char *P) {
  if (*P == '\0')
    return *S == '\0';
  if (*S == '\0')
    return *(P + 1) == '*' && match(S, P + 2);
  if (*(P + 1) == '*') {
    if (*P == '.' || *S == *P)
      return match(S, P + 2) || match(S + 1, P);
    return match(S, P + 2);
  }
  return (*P == '.' || *S == *P) && match(S + 1, P + 1);
}

bool Solution10_1::isMatch(std::string s, std::string p) {
  return match(s.c_str(), p.c_str());
}

bool Solution10_2::isMatch(std::string s, std::string p) {
  typedef std::string::size_type SizeType;
  const auto &M = s.size(), &N = p.size();
  if (N == 0)
    return M == 0;
  std::vector<std::vector<bool>> Dp(M + 1, std::vector<bool>(N + 1));
  Dp[0][0] = true;
  for (SizeType J = 2, E = N + N % 2 + 2; J != E && p[J - 1] == '*'; J += 2)
    Dp[0][J] = true;
  if (M != 0 && (p[0] == '.' || p[0] == s[0]))
    Dp[1][1] = true;
  for (SizeType I = 1, IE = M + 1; I != IE; ++I) {
    for (SizeType J = 2, JE = N + 1; J != JE; ++J) {
      const auto &ChS = s[I - 1], &ChP = p[J - 1];
      if (ChP != '*') {
        Dp[I][J] = (ChP == '.' || ChP == ChS) && Dp[I - 1][J - 1];
      } else {
        Dp[I][J] = Dp[I][J - 2] ||
                   ((p[J - 2] == '.' || p[J - 2] == ChS) && Dp[I - 1][J]);
      }
    }
  }
  return Dp[M][N];
}
