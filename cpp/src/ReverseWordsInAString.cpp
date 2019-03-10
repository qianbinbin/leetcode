#include "ReverseWordsInAString.h"

using namespace lcpp;

std::string Solution151_1::reverseWords(std::string s) {
  std::string Result;
  auto RI = s.crbegin(), RJ = RI, RE = s.crend();
  while (RI != RE) {
    while (RI != RE && *RI == ' ')
      ++RI;
    RJ = RI;
    while (RJ != RE && *RJ != ' ')
      ++RJ;
    Result += std::string(RJ.base(), RI.base()) + ' ';
    RI = RJ;
  }
  auto I = Result.crbegin(), E = Result.crend();
  while (I != E && *I == ' ')
    ++I;
  Result.erase(I.base(), Result.end());
  return Result;
}
