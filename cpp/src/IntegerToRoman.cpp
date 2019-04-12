#include "IntegerToRoman.h"
#include <cassert>

using namespace lcpp;

const std::array<int, 13> Solution12_1::Values{1000, 900, 500, 400, 100, 90, 50,
                                               40,   10,  9,   5,   4,   1};

const std::array<std::string, 13> &Solution12_1::getSymbols() {
  static const std::array<std::string, 13> Symbols{
      "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  return Symbols;
}

inline std::string operator*(const std::string &Str, std::string::size_type N) {
  std::string Result;
  Result.reserve(N * Str.size());
  for (; N != 0; --N)
    Result += Str;
  return Result;
}

std::string Solution12_1::intToRoman(int num) {
  assert(0 < num && num < 4000);
  std::string Result;
  auto Symbols = getSymbols();
  for (std::size_t I = 0, Count; I != 13; ++I) {
    if ((Count = num / Values[I]) == 0)
      continue;
    Result += Symbols[I] * Count;
    num -= Values[I] * Count;
  }
  return Result;
}
