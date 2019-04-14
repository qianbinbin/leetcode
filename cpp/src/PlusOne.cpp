#include "PlusOne.h"

using namespace lcpp;

std::vector<int> Solution66_1::plusOne(std::vector<int> &digits) {
  auto Result = digits;
  int Carry = 1;
  for (auto RI = Result.rbegin(), RE = Result.rend(); RI != RE; ++RI) {
    *RI += Carry;
    Carry = *RI / 10;
    *RI %= 10;
  }
  if (Carry != 0)
    Result.insert(Result.begin(), Carry);
  return Result;
}
