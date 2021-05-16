#include "RotateImage.h"
#include <algorithm>

using namespace lcpp;

void Solution48_1::rotate(std::vector<std::vector<int>> &matrix) {
  for (decltype(matrix.size()) I = 0, E = matrix.size(); I != E; ++I)
    for (auto J = I + 1; J != E; ++J)
      std::swap(matrix[I][J], matrix[J][I]);
  for (auto &Row : matrix)
    std::reverse(Row.begin(), Row.end());
}
