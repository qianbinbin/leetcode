#include "ImplementQueueUsingStacks.h"

using namespace lcpp;

void MyQueue::push(int x) { Stack1.push(x); }

int MyQueue::pop() {
  makeSureFront();
  int Value = Stack2.top();
  Stack2.pop();
  return Value;
}

int MyQueue::peek() {
  makeSureFront();
  return Stack2.top();
}

bool MyQueue::empty() { return Stack1.empty() && Stack2.empty(); }

void MyQueue::makeSureFront() {
  if (!Stack2.empty())
    return;
  while (!Stack1.empty()) {
    Stack2.push(Stack1.top());
    Stack1.pop();
  }
}
