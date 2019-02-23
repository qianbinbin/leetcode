#include "LargestRectangleInHistogram.h"
#include <stack>

using namespace lcpp;

int Solution84_1::largestRectangleArea(std::vector<int> &heights) {
  heights.push_back(0);
  typedef std::vector<int>::size_type SizeType;
  SizeType Largest = 0;
  std::stack<SizeType> Stack;
  for (SizeType I = 0, E = heights.size(), J, Area; I != E;) {
    if (Stack.empty() || heights[I] >= heights[Stack.top()]) {
      Stack.push(I++);
    } else {
      J = Stack.top();
      Stack.pop();
      Area = heights[J] * (Stack.empty() ? I : I - Stack.top() - 1);
      if (Area > Largest)
        Largest = Area;
    }
  }
  heights.pop_back();
  return static_cast<int>(Largest);
}
