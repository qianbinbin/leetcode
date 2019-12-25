#include "PalindromeNumber.h"
#include <algorithm>
#include <cstdint>
#include <string>

using namespace lcpp;

bool Solution9_1::isPalindrome(int x) {
  auto S1 = std::to_string(x), S2 = S1;
  std::reverse(S2.begin(), S2.end());
  return S1 == S2;
}

bool Solution9_2::isPalindrome(int x) {
  if (x < 0)
    return false;
  int64_t Origin = static_cast<int64_t>(x), Reverse = 0;
  while (x != 0) {
    Reverse = Reverse * 10 + x % 10;
    x /= 10;
  }
  return Origin == Reverse;
}
