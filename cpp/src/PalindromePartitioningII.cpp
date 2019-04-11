#include "PalindromePartitioningII.h"
#include <vector>

using namespace lcpp;

int Solution132_1::minCut(std::string s) {
  const auto &Size = s.size();
  if (Size < 2)
    return 0;
  std::vector<std::vector<bool>> Palindrome(Size, std::vector<bool>(Size + 1));
  std::vector<int> Cut(Size + 1);
  int Tmp = Size;
  for (auto &C : Cut)
    C = --Tmp;
  Palindrome[Size - 1][0] = true;
  Palindrome[Size - 1][1] = true;
  for (std::string::size_type I = Size - 2, IE = -1; I != IE; --I) {
    auto &P = Palindrome[I], &PN = Palindrome[I + 1];
    P[0] = true;
    P[1] = true;
    auto &C = Cut[I];
    C = std::min(C, Cut[I + 1] + 1);
    const auto &Ch = s[I];
    for (std::string::size_type L = 2, LE = Size - I + 1; L != LE; ++L) {
      if (Ch == s[I + L - 1] && PN[L - 2]) {
        P[L] = true;
        C = std::min(C, Cut[I + L] + 1);
      }
    }
  }
  return Cut[0];
}
