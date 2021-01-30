#include "IntegerToRoman.h"
#include <array>

using namespace lcpp;

static const std::array<std::pair<int, std::string>, 13> &getMap() {
  static const std::array<std::pair<int, std::string>, 13> Map{
      std::make_pair(1000, "M"), std::make_pair(900, "CM"),
      std::make_pair(500, "D"),  std::make_pair(400, "CD"),
      std::make_pair(100, "C"),  std::make_pair(90, "XC"),
      std::make_pair(50, "L"),   std::make_pair(40, "XL"),
      std::make_pair(10, "X"),   std::make_pair(9, "IX"),
      std::make_pair(5, "V"),    std::make_pair(4, "IV"),
      std::make_pair(1, "I")};
  return Map;
}

std::string Solution12_1::intToRoman(int num) {
  std::string Result;
  auto &Map = getMap();
  int Count;
  for (auto &Roman : Map) {
    if ((Count = num / Roman.first) == 0)
      continue;
    num -= Roman.first * Count;
    for (; Count != 0; --Count)
      Result += Roman.second;
  }
  return Result;
}
