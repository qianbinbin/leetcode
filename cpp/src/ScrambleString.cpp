#include "ScrambleString.h"
#include <cassert>
#include <vector>

using namespace lcpp;

typedef std::string::size_type SizeType;

bool Solution87_1::isScramble(std::string s1, std::string s2) {
  const auto &Size = s1.size();
  assert(Size != 0 && s2.size() == Size);
  std::vector<std::vector<std::vector<bool>>> Dp(
      Size, std::vector<std::vector<bool>>(Size, std::vector<bool>(Size)));
  for (SizeType I = 0; I != Size; ++I) {
    for (SizeType J = 0; J != Size; ++J) {
      if (s1[I] == s2[J])
        Dp[0][I][J] = true;
    }
  }
  for (SizeType L = 1; L != Size; ++L) { // length = L + 1
    for (SizeType I = 0, E = Size - L; I != E; ++I) {
      for (SizeType J = 0; J != E; ++J) {
        for (SizeType K = 0; K != L; ++K) {
          if ((Dp[K][I][J] && Dp[L - K - 1][I + K + 1][J + K + 1]) ||
              (Dp[K][I][J + L - K] && Dp[L - K - 1][I + K + 1][J])) {
            Dp[L][I][J] = true;
            break;
          }
        }
      }
    }
  }
  return Dp[Size - 1][0][0];
}

/// Assert both S1 and S2 only contain lower case letters.
static bool isScramble(std::string &S1, std::string &S2, SizeType I, SizeType J,
                       SizeType L) {
  if (L == 1)
    return S1[I] == S2[J];
  SizeType Count[26]{0};
  for (SizeType K = 0; K != L; ++K) {
    ++Count[S1[I + K] - 'a'];
    --Count[S2[J + K] - 'a'];
  }
  for (const auto &C : Count)
    if (C != 0)
      return false;
  for (SizeType K = 1; K != L; ++K) {
    if ((isScramble(S1, S2, I, J, K) &&
         isScramble(S1, S2, I + K, J + K, L - K)) ||
        (isScramble(S1, S2, I, J + L - K, K) &&
         isScramble(S1, S2, I + K, J, L - K)))
      return true;
  }
  return false;
}

bool Solution87_2::isScramble(std::string s1, std::string s2) {
  const auto &Size = s1.size();
  assert(Size != 0 && s2.size() == Size);
  return ::isScramble(s1, s2, 0, 0, Size);
}
