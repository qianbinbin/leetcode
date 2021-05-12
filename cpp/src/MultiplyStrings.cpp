#include "MultiplyStrings.h"

using namespace lcpp;

static std::string operator*(std::string const &Int1, std::string const &Int2) {
  auto const &Size1 = Int1.size(), &Size2 = Int2.size();
  std::string Result;
  Result.resize(Size1 + Size2);
  for (std::string::size_type J = Size2 - 1, I, E = -1; J != E; --J) {
    for (I = Size1 - 1; I != E; --I) {
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
