#include "PascalsTriangle.h"

using namespace lcpp;

std::vector<std::vector<int>> Solution118_1::generate(int numRows) {
  std::vector<std::vector<int>> Result{{1}};
  for (int I = 1, J; I != numRows; ++I) {
    Result.emplace_back(I + 1);
    auto &Pre = Result[I - 1], &Cur = Result[I];
    Cur[0] = Cur[I] = 1;
    for (J = 1; J != I; ++J)
      Cur[J] = Pre[J - 1] + Pre[J];
  }
  return Result;
}
