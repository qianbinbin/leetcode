#include "RomanToInteger.h"
#include <array>

using namespace lcpp;

static const std::array<std::pair<std::string, int>, 13> &getMap() {
  static const std::array<std::pair<std::string, int>, 13> Map = {
      std::make_pair("M", 1000), std::make_pair("CM", 900),
      std::make_pair("D", 500),  std::make_pair("CD", 400),
      std::make_pair("C", 100),  std::make_pair("XC", 90),
      std::make_pair("L", 50),   std::make_pair("XL", 40),
      std::make_pair("X", 10),   std::make_pair("IX", 9),
      std::make_pair("V", 5),    std::make_pair("IV", 4),
      std::make_pair("I", 1)};
  return Map;
}

int Solution13_1::romanToInt(std::string s) {
  auto &Map = getMap();
  int Result = 0;
  for (auto &Roman : Map) {
    while (s.rfind(Roman.first, 0) == 0) {
      Result += Roman.second;
      s = s.substr(Roman.first.size());
    }
  }
  return Result;
}
