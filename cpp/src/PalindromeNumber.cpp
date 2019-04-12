#include "PalindromeNumber.h"
#include <string>

using namespace lcpp;

bool Solution9_1::isPalindrome(int x) {
  auto S1 = std::to_string(x), S2 = S1;
  std::reverse(S2.begin(), S2.end());
  return S1 == S2;
}
