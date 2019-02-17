#include "SpiralMatrixII.h"
#include <cassert>

using namespace lcpp;

std::vector<std::vector<int>> Solution59_1::generateMatrix(int n) {
  assert(n >= 0 && "n must be non-negative!");
  const auto N = static_cast<std::vector<int>::size_type>(n);
  std::vector<std::vector<int>> Matrix(N, std::vector<int>(N));
  int Number = 1, Left = 0, Right = n - 1, Top = 0, Bottom = n - 1, I, J;
  while (true) {
    for (J = Left; J <= Right; ++J)
      Matrix[Top][J] = Number++;
    if (++Top > Bottom)
      break;
    for (I = Top; I <= Bottom; ++I)
      Matrix[I][Right] = Number++;
    if (--Right < Left)
      break;
    for (J = Right; J >= Left; --J)
      Matrix[Bottom][J] = Number++;
    if (--Bottom < Top)
      break;
    for (I = Bottom; I >= Top; --I)
      Matrix[I][Left] = Number++;
    if (++Left > Right)
      break;
  }
  return Matrix;
}
