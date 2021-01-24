#include "StringToIntegerAtoi.h"
#include <climits>

using namespace lcpp;

int Solution8_1::myAtoi(std::string str) {
  auto I = str.begin(), E = str.end();
  while (I != E && *I == ' ')
    ++I;
  if (I == E)
    return 0;
  bool IsNegative = false;
  if (*I == '+') {
    ++I;
  } else if (*I == '-') {
    IsNegative = true;
    ++I;
  }

  const auto Limit = INT_MAX / 10;
  int Value = 0;
  for (; I != E && isdigit(*I); ++I) {
    if (Value > Limit || (Value == Limit && *I - '0' > 7))
      return IsNegative ? INT_MIN : INT_MAX;
    // int overflow, dupe LeetCode compiler
    // Value = Value * 10 + *I - '0';
    Value = Value * 10 + (*I - '0');
  }
  return static_cast<int>(IsNegative ? -Value : Value);
}
