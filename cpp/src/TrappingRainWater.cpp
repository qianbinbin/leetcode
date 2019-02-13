#include "TrappingRainWater.h"

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
  int Water = 0, Column;
  for (auto I = Size - 2; I != 0; --I) {
    RightMax[I] = std::max(RightMax[I + 1], height[I + 1]);
    Column = std::min(LeftMax[I], RightMax[I]) - height[I];
    if (Column > 0)
      Water += Column;
  }
  return Water;
}
