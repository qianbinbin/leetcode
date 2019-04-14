#include "SingleNumber.h"

using namespace lcpp;

int Solution136_1::singleNumber(std::vector<int> &nums) {
  int Result = 0;
  for (const auto &N : nums)
    Result ^= N;
  return Result;
}
