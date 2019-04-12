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
