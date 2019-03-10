#include "ValidNumber.h"

using namespace lcpp;

bool Solution65_1::isNumber(std::string s) {
  auto I = s.cbegin(), E = s.cend();
  while (I != E && *I == ' ')
    ++I;
  if (I == E)
    return false;

  if (*I == '+' || *I == '-')
    ++I;
  bool Digit = false, Point = false;
  while (I != E) {
    if (isdigit(*I)) {
      Digit = true;
      ++I;
    } else if (*I == '.') {
      if (Point)
        return false;
      else
        Point = true;
      ++I;
    } else {
      break;
    }
  }
  if (!Digit)
    return false;
  if (I == E)
    return true;
  if (*I != 'e') {
    while (I != E && *I == ' ')
      ++I;
    return I == E;
  }

  if (++I == E)
    return false;
  if (*I == '+' || *I == '-')
    ++I;
  if (I == E)
    return false;
  Digit = false;
  while (I != E && isdigit(*I)) {
    Digit = true;
    ++I;
  }
  if (!Digit)
    return false;
  while (I != E && *I == ' ')
    ++I;
  return I == E;
}
