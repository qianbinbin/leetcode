#include "SetMatrixZeroes.h"

using namespace lcpp;

void Solution73_1::setZeroes(std::vector<std::vector<int>> &matrix) {
  auto M = matrix.size();
  if (M == 0)
    return;
  auto N = matrix[0].size();
  if (N == 0)
    return;
  bool SetFirstRow = false, SetFirstColumn = false;
  for (const auto &I : matrix[0]) {
    if (I == 0) {
      SetFirstRow = true;
      break;
    }
  }
  for (const auto &Row : matrix) {
    if (Row[0] == 0) {
      SetFirstColumn = true;
      break;
    }
  }
  for (decltype(M) I = 1; I != M; ++I) {
    for (decltype(N) J = 1; J != N; ++J) {
      if (matrix[I][J] == 0) {
        matrix[I][0] = 0;
        matrix[0][J] = 0;
      }
    }
  }
  for (decltype(M) I = 1; I != M; ++I) {
    if (matrix[I][0] == 0)
      for (decltype(N) J = 1; J != N; ++J)
        matrix[I][J] = 0;
  }
  for (decltype(N) J = 1; J != N; ++J) {
    if (matrix[0][J] == 0)
      for (decltype(M) I = 1; I != M; ++I)
        matrix[I][J] = 0;
  }
  if (SetFirstRow)
    for (auto &I : matrix[0])
      I = 0;
  if (SetFirstColumn)
    for (auto &Row : matrix)
      Row[0] = 0;
}
