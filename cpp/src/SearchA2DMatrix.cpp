#include "SearchA2DMatrix.h"

using namespace lcpp;

bool Solution74_1::searchMatrix(std::vector<std::vector<int>> &matrix,
                                int target) {
  const auto &M = matrix.size();
  if (M == 0)
    return false;
  const auto &N = matrix[0].size();
  if (N == 0)
    return false;
  // TODO: check multiplication overflow.
  int Low = 0, High = static_cast<int>(M * N) - 1, Mid;
  while (Low <= High) {
    Mid = Low + (High - Low) / 2;
    const auto &Value = matrix[Mid / N][Mid % N];
    if (Value < target) {
      Low = Mid + 1;
    } else if (Value > target) {
      High = Mid - 1;
    } else {
      return true;
    }
  }
  return false;
}
