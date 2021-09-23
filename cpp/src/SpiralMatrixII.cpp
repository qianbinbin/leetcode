#include "SpiralMatrixII.h"

using namespace lcpp;

std::vector<std::vector<int>> Solution59_1::generateMatrix(int n) {
  std::vector<std::vector<int>> Matrix(n, std::vector<int>(n));
  int Left = 0, Right = n - 1, Top = 0, Bottom = n - 1, I, J;
  int Num = 1;
  while (true) {
    for (J = Left; J <= Right; ++J)
      Matrix[Top][J] = Num++;
    if (++Top > Bottom)
      break;
    for (I = Top; I <= Bottom; ++I)
      Matrix[I][Right] = Num++;
    if (--Right < Left)
      break;
    for (J = Right; J >= Left; --J)
      Matrix[Bottom][J] = Num++;
    if (--Bottom < Top)
      break;
    for (I = Bottom; I >= Top; --I)
      Matrix[I][Left] = Num++;
    if (++Left > Right)
      break;
  }
  return Matrix;
}
