#include "ProductOfArrayExceptSelf.h"
#include <cassert>

using namespace lcpp;

std::vector<int> Solution238_1::productExceptSelf(std::vector<int> &nums) {
  const auto &Size = nums.size();
  assert(Size > 1);
  std::vector<int> Result(Size, 1);
  for (std::vector<int>::size_type I = 1; I != Size; ++I)
    Result[I] = Result[I - 1] * nums[I - 1];
  int RightProduct = 1;
  for (auto I = Size - 1; I != -1; --I) {
    Result[I] *= RightProduct;
    RightProduct *= nums[I];
  }
  return Result;
}
