#include "SearchA2DMatrixII.h"

using namespace lcpp;

bool Solution240_1::searchMatrix(std::vector<std::vector<int>> &matrix,
                                 int target) {
  auto IE = matrix.size();
  if (IE == 0)
    return false;
  auto JE = matrix[0].size();
  if (JE == 0)
    return false;
  decltype(IE) I = 0;
  auto J = JE - 1;
  while (I != IE && J != -1) {
    const auto &Val = matrix[I][J];
    if (Val == target)
      return true;
    else if (Val < target)
      ++I;
    else
      --J;
  }
  return false;
}
