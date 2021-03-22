#include "LongestValidParentheses.h"
#include <stack>
#include <vector>

using namespace lcpp;

int Solution32_1::longestValidParentheses(std::string s) {
  std::string::difference_type StackSize = 0, Longest = 0;
  for (auto I = s.begin(), E = s.end(), Start = I; I != E; ++I) {
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
  for (auto I = s.rbegin(), E = s.rend(), Start = I; I != E; ++I) {
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
  return Longest;
}

int Solution32_2::longestValidParentheses(std::string s) {
  auto const &Size = s.size();
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
  auto const &Size = s.size();
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
