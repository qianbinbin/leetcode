#include "SpiralMatrix.h"

using namespace lcpp;

std::vector<int> Solution54_1::spiralOrder(
    std::vector<std::vector<int>> &matrix) {
  std::vector<int> Result;
  auto M = matrix.size();
  if (M == 0)
    return Result;
  auto N = matrix[0].size();
  if (N == 0)
    return Result;
  decltype(M) Top = 0, Bottom = M - 1, I;
  decltype(N) Left = 0, Right = N - 1, J;
  while (true) {
    for (J = Left; J != Right + 1; ++J)
      Result.push_back(matrix[Top][J]);
    if (++Top == Bottom + 1)
      break;
    for (I = Top; I != Bottom + 1; ++I)
      Result.push_back(matrix[I][Right]);
    if (--Right == Left - 1)
      break;
    for (J = Right; J != Left - 1; --J)
      Result.push_back(matrix[Bottom][J]);
    if (--Bottom == Top - 1)
      break;
    for (I = Bottom; I != Top - 1; --I)
      Result.push_back(matrix[I][Left]);
    if (++Left == Right + 1)
      break;
  }
  return Result;
}
