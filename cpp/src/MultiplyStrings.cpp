#include "MultiplyStrings.h"
#include <cassert>

using namespace lcpp;

static std::string operator*(const std::string &Int1, const std::string &Int2) {
  const auto &Size1 = Int1.size(), &Size2 = Int2.size();
  assert(Size1 != 0 && Size2 != 0);
  std::string Result;
  Result.resize(Size1 + Size2);
  for (std::string::size_type J = Size2 - 1; J != -1; --J) {
    for (std::string::size_type I = Size1 - 1; I != -1; --I) {
      Result[I + J + 1] += (Int1[I] - '0') * (Int2[J] - '0');
      Result[I + J] += Result[I + J + 1] / 10;
      Result[I + J + 1] %= 10;
    }
  }
  for (auto &Ch : Result)
    Ch += '0';
  std::string::size_type High = 0, Low = Size1 + Size2 - 1;
  while (High != Low && Result[High] == '0')
    ++High;
  return High == 0 ? Result : Result.substr(High, Size1 + Size2 - High);
}

std::string Solution43_1::multiply(std::string num1, std::string num2) {
  return num1 * num2;
}
