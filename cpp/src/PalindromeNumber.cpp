#include "PalindromeNumber.h"

using namespace lcpp;

bool Solution9_1::isPalindrome(int x) {
  if (x < 0)
    return false;
  // int overflow, dupe LeetCode compiler
  // int Old = x, New = 0;
  unsigned int Old = x, New = 0;
  for (; x != 0; x /= 10)
    New = New * 10 + x % 10;
  return Old == New;
}
