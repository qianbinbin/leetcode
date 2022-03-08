#include "PalindromePartitioningII.h"
#include <vector>

using namespace lcpp;

int Solution132_1::minCut(std::string s) {
  const auto &Size = s.size();
  std::vector<std::vector<bool>> Palindrome(Size, std::vector<bool>(Size));
  std::vector<int> Cut(Size + 1);
  int Tmp = Size;
  for (auto &C : Cut)
    C = --Tmp;
  for (std::string::size_type I = Size - 1, IE = -1, J; I != IE; --I) {
    for (J = I; J != Size; ++J) {
      if (s[I] == s[J] && (J - I < 2 || Palindrome[I + 1][J - 1])) {
        Palindrome[I][J] = true;
        Cut[I] = std::min(Cut[I], Cut[J + 1] + 1);
      }
    }
  }
  return Cut[0];
}

int Solution132_2::minCut(std::string s) {
  const auto &Size = s.size();
  std::vector<int> Cut(Size + 1);
  int Tmp = -1;
  for (auto &C : Cut)
    C = Tmp++;
  for (std::string::size_type I = 0, L, LE; I != Size; ++I) {
    for (L = 0, LE = std::min(I + 1, Size - I); L != LE && s[I - L] == s[I + L];
         ++L)
      Cut[I + L + 1] = std::min(Cut[I + L + 1], Cut[I - L] + 1);
    for (L = 0, LE = std::min(I + 1, Size - I - 1);
         L != LE && s[I - L] == s[I + L + 1]; ++L)
      Cut[I + L + 2] = std::min(Cut[I + L + 2], Cut[I - L] + 1);
  }
  return Cut[Size];
}
