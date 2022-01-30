#include "DecodeWays.h"

using namespace lcpp;

int Solution91_1::numDecodings(std::string s) {
  auto I = s.begin(), E = s.end();
  int PrePre = 1, Pre = *I == '0' ? 0 : 1, Dp = Pre;
  for (++I; I != E; ++I) {
    Dp = *I == '0' ? 0 : Pre;
    if (*(I - 1) == '1' || (*(I - 1) == '2' && *I <= '6'))
      Dp += PrePre;
    PrePre = Pre;
    Pre = Dp;
  }
  return Dp;
}
