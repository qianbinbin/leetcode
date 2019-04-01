#include "LongestPalindromicSubstring.h"
#include <vector>

using namespace lcpp;

std::string Solution5_1::longestPalindrome(std::string s) {
  const auto &Size = s.size();
  std::string::size_type Start = 0, Length = 0;
  std::vector<std::vector<bool>> Dp(Size, std::vector<bool>(Size));
  for (auto I = Size - 1; I != -1; --I) {
    for (auto J = I; J != Size; ++J) {
      if (I == J || (s[I] == s[J] && (I + 1 == J || Dp[I + 1][J - 1]))) {
        Dp[I][J] = true;
        if (J - I + 1 > Length) {
          Length = J - I + 1;
          Start = I;
        }
      }
    }
  }
  return std::string(s, Start, Length);
}
