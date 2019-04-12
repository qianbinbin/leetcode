#include "ReverseInteger.h"
#include <cstdint>
#include <limits>
#include <string>

using namespace lcpp;

int Solution7_1::reverse(int x) {
  auto S = std::to_string(std::abs(static_cast<int64_t>(x)));
  std::reverse(S.begin(), S.end());
  int64_t Result = std::stoll(S) * (x < 0 ? -1 : 1);
  if (Result > std::numeric_limits<int>::max() ||
      Result < std::numeric_limits<int>::min())
    return 0;
  return Result;
}

int Solution7_2::reverse(int x) {
  int Sign = x < 0 ? -1 : 1;
  int64_t Result = 0, Value = std::abs(static_cast<int64_t>(x));
  while (Value != 0) {
    Result = Result * 10 + Value % 10;
    Value /= 10;
  }
  Result *= Sign;
  if (Result > std::numeric_limits<int>::max() ||
      Result < std::numeric_limits<int>::min())
    return 0;
  return Result;
}
