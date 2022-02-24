#include "PascalsTriangleII.h"

using namespace lcpp;

std::vector<int> Solution119_1::getRow(int rowIndex) {
  int E = rowIndex + 1;
  std::vector<int> Result(E);
  for (int I = 0, J; I != E; ++I) {
    Result[I] = 1;
    for (J = I - 1; J > 0; --J)
      Result[J] += Result[J - 1];
  }
  return Result;
}
