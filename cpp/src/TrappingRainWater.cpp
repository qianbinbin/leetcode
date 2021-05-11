#include "TrappingRainWater.h"
#include <stack>

using namespace lcpp;

int Solution42_1::trap(std::vector<int> &height) {
  auto Size = height.size();
  if (Size < 3)
    return 0;
  std::vector<int> LeftMax(Size);
  LeftMax[0] = 0;
  for (decltype(Size) I = 1; I != Size - 1; ++I)
    LeftMax[I] = std::max(LeftMax[I - 1], height[I - 1]);
  std::vector<int> RightMax(Size);
  RightMax[Size - 1] = 0;
  int Result = 0, Bar;
  for (auto I = Size - 2; I != 0; --I) {
    RightMax[I] = std::max(RightMax[I + 1], height[I + 1]);
    Bar = std::min(LeftMax[I], RightMax[I]) - height[I];
    if (Bar > 0)
      Result += Bar;
  }
  return Result;
}

int Solution42_2::trap(std::vector<int> &height) {
  auto const Size = height.size();
  if (Size < 3)
    return 0;
  typedef std::vector<int>::size_type SizeType;
  SizeType Result = 0;
  std::stack<SizeType> Stack; // indices to trace descending height[i]
  SizeType I, J, LeftBound;
  for (I = 0; I != Size; ++I) {
    while (!Stack.empty() && height[I] > height[J = Stack.top()]) {
      Stack.pop();
      if (Stack.empty())
        break;
      LeftBound = Stack.top();
      Result += (std::min(height[LeftBound], height[I]) - height[J]) *
                (I - LeftBound - 1);
    }
    Stack.push(I);
  }
  return static_cast<int>(Result);
}

int Solution42_3::trap(std::vector<int> &height) {
  if (height.size() < 3)
    return 0;
  int Result = 0, LMax = 0, RMax = 0;
  auto I = height.begin(),
       J = height.end() - 1; // either pointing to max value found so far
  while (I != J) {
    if (*I <= *J) {
      if (LMax <= *I)
        LMax = *I;
      else
        Result += LMax - *I;
      ++I;
    } else {
      if (RMax <= *J)
        RMax = *J;
      else
        Result += RMax - *J;
      --J;
    }
  }
  return Result;
}
