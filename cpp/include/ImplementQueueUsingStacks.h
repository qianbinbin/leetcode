// Implement the following operations of a queue using stacks.
//
// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.
//
// Example:
//
// MyQueue queue = new MyQueue();
//
// queue.push(1);
// queue.push(2);
// queue.peek();  // returns 1
// queue.pop();   // returns 1
// queue.empty(); // returns false
//
// Notes:
//
// You must use only standard operations of a stack -- which means only push to
// top, peek/pop from top, size, and is empty operations are valid.

// Depending on your language, stack may not be supported natively. You may
// simulate a stack by using a list or deque (double-ended queue), as long as
// you use only standard operations of a stack.

// You may assume that all operations are valid (for example, no pop or peek
// operations will be called on an empty queue).

#ifndef LEETCODECPP_IMPLEMENTQUEUEUSINGSTACKS_H
#define LEETCODECPP_IMPLEMENTQUEUEUSINGSTACKS_H

#include <stack>

namespace lcpp {

class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() = default;

  /** Push element x to the back of queue. */
  void push(int x);

  /** Removes the element from in front of queue and returns that element. */
  int pop();

  /** Get the front element. */
  int peek();

  /** Returns whether the queue is empty. */
  bool empty();

private:
  std::stack<int> Stack1;

  std::stack<int> Stack2;

  void makeSureFront();
};

} // namespace lcpp

#endif // LEETCODECPP_IMPLEMENTQUEUEUSINGSTACKS_H
