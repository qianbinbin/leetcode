#include "ValidParentheses.h"
#include <stack>

using namespace lcpp;

bool Solution20_1::isValid(std::string s) {
  std::stack<char> Stack;
  for (const auto &Char : s) {
    switch (Char) {
    case '(':
    case '[':
    case '{':Stack.push(Char);
      break;
    case ')':
      if (Stack.empty() || Stack.top() != '(')
        return false;
      Stack.pop();
      break;
    case ']':
      if (Stack.empty() || Stack.top() != '[')
        return false;
      Stack.pop();
      break;
    case '}':
      if (Stack.empty() || Stack.top() != '{')
        return false;
      Stack.pop();
      break;
    default:break;
    }
  }
  return Stack.empty();
}
