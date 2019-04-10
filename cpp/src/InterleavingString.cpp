#include "InterleavingString.h"
#include <vector>

using namespace lcpp;

typedef std::string::size_type SizeType;

bool Solution97_1::isInterleave(std::string s1, std::string s2,
                                std::string s3) {
  if (s1.size() < s2.size())
    std::swap(s1, s2);
  const auto &L1 = s1.size(), &L2 = s2.size(), &L3 = s3.size();
  if (L1 + L2 != L3)
    return false;
  const auto M = L1 + 1, N = L2 + 1;
  std::vector<bool> Dp(N);
  Dp[0] = true;
  for (SizeType J = 1; J != N; ++J) {
    if (s2[J - 1] == s3[J - 1])
      Dp[J] = true;
    else
      break;
  }
  for (SizeType I = 1; I != M; ++I) {
    if (Dp[0] && s1[I - 1] != s3[I - 1])
      Dp[0] = false;
    for (SizeType J = 1; J != N; ++J) {
      Dp[J] = (s1[I - 1] == s3[I + J - 1] && Dp[J]) ||
              (s2[J - 1] == s3[I + J - 1] && Dp[J - 1]);
    }
  }
  return Dp[L2];
}
