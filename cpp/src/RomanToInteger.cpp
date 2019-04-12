#include "RomanToInteger.h"

using namespace lcpp;

const std::unordered_map<std::string, int> &Solution13_1::getMap() {
  static const std::unordered_map<std::string, int> Map{
      {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
      {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
      {"V", 5},    {"IV", 4},   {"I", 1}};
  return Map;
}

int Solution13_1::romanToInt(std::string s) {
  int Value = 0;
  auto &Map = getMap();
  std::unordered_map<std::string, int>::const_iterator It, ME = Map.cend();
  for (std::string::size_type I = 0, E = s.size(); I != E;) {
    if (I + 1 != E && (It = Map.find(s.substr(I, 2))) != ME) {
      I += 2;
    } else {
      It = Map.find(s.substr(I, 1));
      ++I;
    }
    Value += It->second;
  }
  return Value;
}
