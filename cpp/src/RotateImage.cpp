#include "RotateImage.h"
#include <algorithm>

using namespace lcpp;

void Solution48_1::rotate(std::vector<std::vector<int>> &matrix) {
  auto N = matrix.size();
  if (N < 2)
    return;
  for (decltype(N) I = 0; I != N - 1; ++I)
    for (auto J = I + 1; J != N; ++J)
      std::swap(matrix[I][J], matrix[J][I]);
  for (auto &Row : matrix)
    std::reverse(Row.begin(), Row.end());
}
