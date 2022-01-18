#include "ValidNumber.h"

using namespace lcpp;

bool Solution65_1::isNumber(std::string s) {
  auto B = s.begin(), I = B, E = s.end();
  bool Digit = false, Point = false, Exp = false;
  for (; I != E; ++I) {
    if (*I == '+' || *I == '-') {
      if (I != B && *(I - 1) != 'e' && *(I - 1) != 'E')
        return false;
    } else if ('0' <= *I && *I <= '9') {
      Digit = true;
    } else if (*I == '.') {
      if (Point || Exp)
        return false;
      Point = true;
    } else if (*I == 'e' || *I == 'E') {
      if (Exp || !Digit)
        return false;
      Exp = true;
      Digit = false;
    } else {
      break;
    }
  }
  return I == E && Digit;
}
