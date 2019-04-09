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
