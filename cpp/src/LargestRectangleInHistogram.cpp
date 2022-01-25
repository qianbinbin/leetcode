#include "LargestRectangleInHistogram.h"
#include <stack>

using namespace lcpp;

int Solution84_1::largestRectangleArea(std::vector<int> &heights) {
  heights.push_back(0);
  typedef std::vector<int>::size_type SizeType;
  SizeType Result = 0;
  std::stack<SizeType> Stack;
  for (SizeType I = 0, E = heights.size(), J, Left; I != E; ++I) {
    while (!Stack.empty() && heights[I] <= heights[Stack.top()]) {
      J = Stack.top();
      Stack.pop();
      Left = Stack.empty() ? 0 : Stack.top() + 1;
      Result = std::max(Result, heights[J] * (I - Left));
    }
    Stack.push(I);
  }
  heights.pop_back();
  return static_cast<int>(Result);
}
