#include "LongestValidParentheses.h"
#include <cassert>
#include <limits>
#include <stack>
#include <vector>

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

int Solution32_2::longestValidParentheses(std::string s) {
  const auto &Size = s.size();
  assert(Size <= std::numeric_limits<int>::max() && "s size overflow!");
  std::stack<int> Stack;
  Stack.push(-1);
  int Longest = 0;
  for (int I = 0; I != Size; ++I) {
    if (s[I] == '(') {
      Stack.push(I);
    } else if (s[I] == ')') {
      Stack.pop();
      if (Stack.empty()) {
        Stack.push(I);
      } else {
        Longest = std::max(Longest, I - Stack.top());
      }
    }
  }
  return Longest;
}

int Solution32_3::longestValidParentheses(std::string s) {
  const auto &Size = s.size();
  assert(Size <= std::numeric_limits<int>::max() && "s size overflow!");
  if (Size < 2)
    return 0;
  std::vector<int> Dp(Size, 0);
  int Longest = 0;
  if (s[0] == '(' && s[1] == ')') {
    Dp[1] = 2;
    Longest = 2;
  }
  for (int I = 2, J; I != Size; ++I) {
    if (s[I] != ')')
      continue;
    if (s[I - 1] == '(') {
      Dp[I] = Dp[I - 2] + 2;
    } else if (s[I - 1] == ')') {
      J = I - Dp[I - 1] - 1;
      if (J >= 0 && s[J] == '(')
        Dp[I] = Dp[I - 1] + 2 + (J > 0 ? Dp[J - 1] : 0);
    }
    Longest = std::max(Longest, Dp[I]);
  }
  return Longest;
}
