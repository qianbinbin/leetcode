#include "StringToIntegerAtoi.h"

using namespace lcpp;

int Solution8_1::myAtoi(std::string str) {
  auto I = str.cbegin(), E = str.cend();
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
  int64_t Result = 0;
  for (; I != E && isdigit(*I); ++I) {
    Result = Result * 10 + *I - '0';
    if (Result > INT32_MAX)
      break;
  }
  if (Result > INT32_MAX)
    return IsNegative ? INT32_MIN : INT32_MAX;
  return static_cast<int>(IsNegative ? -Result : Result);
}
