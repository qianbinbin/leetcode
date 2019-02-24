#include "MinStack.h"

using namespace lcpp;

void MinStack::push(int x) {
  Stack.push(x);
  if (Min.empty() || Min.top() >= x)
    Min.push(x);
  else
    Min.push(Min.top());
}

void MinStack::pop() {
  Stack.pop();
  Min.pop();
}

int MinStack::top() {
  return Stack.top();
}

int MinStack::getMin() {
  return Min.top();
}
