#include "DecodeWays.h"
#include <cassert>

using namespace lcpp;

int Solution91_1::numDecodings(std::string s) {
  assert(!s.empty());
  char PreCh = s[0];
  if (PreCh == '0')
    return 0;
  char Ch;
  int Pre = 1, Dp = 1, Tmp;
  for (auto I = s.cbegin() + 1, E = s.cend(); I != E; ++I) {
    Ch = *I;
    Tmp = Dp;
    if (PreCh == '1' || (PreCh == '2' && Ch <= '6'))
      Dp = Ch == '0' ? Pre : Dp + Pre;
    else if (Ch == '0')
      return 0;
    Pre = Tmp;
    PreCh = Ch;
  }
  return Dp;
}
