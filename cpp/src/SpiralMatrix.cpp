#include "SpiralMatrix.h"

using namespace lcpp;

std::vector<int>
Solution54_1::spiralOrder(std::vector<std::vector<int>> &matrix) {
  std::vector<int> Result;
  auto M = matrix.size();
  auto N = matrix[0].size();
  decltype(M) Top = 0, Bottom = M - 1, I, EI;
  decltype(N) Left = 0, Right = N - 1, J, EJ;
  while (true) {
    for (J = Left, EJ = Right + 1; J != EJ; ++J)
      Result.push_back(matrix[Top][J]);
    if (++Top == Bottom + 1)
      break;
    for (I = Top, EI = Bottom + 1; I != EI; ++I)
      Result.push_back(matrix[I][Right]);
    if (--Right == Left - 1)
      break;
    for (J = Right, EJ = Left - 1; J != EJ; --J)
      Result.push_back(matrix[Bottom][J]);
    if (--Bottom == Top - 1)
      break;
    for (I = Bottom, EI = Top - 1; I != EI; --I)
      Result.push_back(matrix[I][Left]);
    if (++Left == Right + 1)
      break;
  }
  return Result;
}
