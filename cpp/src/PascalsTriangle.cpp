#include "PascalsTriangle.h"
#include <cassert>

using namespace lcpp;

std::vector<std::vector<int>> Solution118_1::generate(int numRows) {
  assert(numRows >= 0 && "numRows must be non-negative!");
  std::vector<std::vector<int>> Triangle;
  if (numRows == 0)
    return Triangle;
  Triangle.push_back({1});
  std::vector<int>::size_type I, J;
  for (I = 1; I != numRows; ++I) {
    Triangle.emplace_back(I + 1);
    auto &Row = Triangle[I];
    Row[0] = 1;
    Row[I] = 1;
    const auto &LastRow = Triangle[I - 1];
    for (J = 1; J != I; ++J)
      Row[J] = LastRow[J - 1] + LastRow[J];
  }
  return Triangle;
}
