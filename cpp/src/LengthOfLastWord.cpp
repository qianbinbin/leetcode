#include "LengthOfLastWord.h"

using namespace lcpp;

int Solution58_1::lengthOfLastWord(std::string s) {
  auto RI = s.crbegin(), RE = s.crend();
  while (RI != RE && *RI == ' ')
    ++RI;
  auto RJ = RI;
  while (RJ != RE && *RJ != ' ')
    ++RJ;
  return static_cast<int>(RJ - RI);
}
