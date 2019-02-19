#include "PascalsTriangleII.h"
#include <cassert>

using namespace lcpp;

std::vector<int> Solution119_1::getRow(int rowIndex) {
  assert(0 <= rowIndex && rowIndex <= 33
             && "rowIndex must be between 0 and 33 inclusive!");
  auto E = static_cast<std::vector<int>::size_type>(rowIndex) + 1;
  std::vector<int> Row(E);
  Row[0] = 1;
  for (decltype(E) I = 1; I != E; ++I) {
    Row[I] = 1;
    for (auto J = I - 1; J != 0; --J)
      Row[J] += Row[J - 1];
  }
  return Row;
}
