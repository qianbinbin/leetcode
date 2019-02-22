#include "LongestValidParentheses.h"
#include <cassert>
#include <limits>

using namespace lcpp;

int Solution32_1::longestValidParentheses(std::string s) {
  std::string::size_type StackSize = 0;
  std::string::difference_type Longest = 0;
  for (auto I = s.cbegin(), E = s.cend(), Start = I; I != E; ++I) {
    if (*I == '(') {
      ++StackSize;
    } else if (*I == ')') {
      if (StackSize != 0) {
        if (--StackSize == 0)
          Longest = std::max(Longest, I - Start + 1);
      } else {
        Start = I + 1;
      }
    }
  }
  StackSize = 0;
  for (auto I = s.crbegin(), E = s.crend(), Start = I; I != E; ++I) {
    if (*I == ')') {
      ++StackSize;
    } else if (*I == '(') {
      if (StackSize != 0) {
        if (--StackSize == 0)
          Longest = std::max(Longest, I - Start + 1);
      } else {
        Start = I + 1;
      }
    }
  }
  assert(Longest <= std::numeric_limits<int>::max() && "Result overflow!");
  return static_cast<int>(Longest);
}
