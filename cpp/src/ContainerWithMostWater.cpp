#include "ContainerWithMostWater.h"
#include <algorithm>

using namespace lcpp;

int lcpp::Solution11_1::maxArea(std::vector<int> &height) {
  int Area = 0;
  auto I = height.begin(), J = height.end() - 1;
  while (I != J) {
    if (*I < *J) {
      Area = std::max(Area, static_cast<int>(J - I) * *I);
      ++I;
    } else {
      Area = std::max(Area, static_cast<int>(J - I) * *J);
      --J;
    }
  }
  return Area;
}
