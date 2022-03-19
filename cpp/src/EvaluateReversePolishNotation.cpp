#include "EvaluateReversePolishNotation.h"
#include <stack>

using namespace lcpp;

int Solution150_1::evalRPN(std::vector<std::string> &tokens) {
  std::stack<int> Stack;
  int Value;
  for (auto const &Token : tokens) {
    if (Token == "+") {
      Value = Stack.top();
      Stack.pop();
      Stack.top() += Value;
    } else if (Token == "-") {
      Value = Stack.top();
      Stack.pop();
      Stack.top() -= Value;
    } else if (Token == "*") {
      Value = Stack.top();
      Stack.pop();
      Stack.top() *= Value;
    } else if (Token == "/") {
      Value = Stack.top();
      Stack.pop();
      Stack.top() /= Value;
    } else {
      Stack.push(std::stoi(Token));
    }
  }
  return Stack.top();
}
