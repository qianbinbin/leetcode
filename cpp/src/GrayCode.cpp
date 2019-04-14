#include "GrayCode.h"
#include <cassert>

using namespace lcpp;

std::vector<int> Solution89_1::grayCode(int n) {
  assert(n >= 0 && "n must be non-negative!");
  unsigned N = n;
  std::vector<int> Result;
  Result.reserve(1u << N);
  Result.push_back(0);
  for (unsigned I = 0; I != N; ++I) {
    const auto Bit = 1u << I;
    for (auto J = Result.size() - 1; J != -1; --J)
      Result.push_back(static_cast<unsigned>(Result[J]) | Bit);
  }
  return Result;
}
