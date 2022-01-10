#include "ImplementStrStr.h"
#include <vector>

using namespace lcpp;

int Solution28_1::strStr(std::string haystack, std::string needle) {
  int IE = haystack.size(), JE = needle.size();
  if (IE < JE)
    return -1;
  int I = 0, J = 0;
  while (I != IE && J != JE) {
    if (haystack[I] != needle[J]) {
      I = I - J + 1;
      J = 0;
    } else {
      ++I;
      ++J;
    }
  }
  return J == JE ? I - J : -1;
}

static std::vector<int> getNext(std::string const &Str) {
  int Size = Str.size();
  std::vector<int> Next(Size, 0);
  Next[0] = -1;
  for (int I = 1, J = -1; I != Size; ++I) {
    while (J != -1 && Str[I - 1] != Str[J])
      J = Next[J];
    ++J;
    Next[I] = Str[I] != Str[J] ? J : Next[J];
  }
  return Next;
}

int Solution28_2::strStr(std::string haystack, std::string needle) {
  int IE = haystack.size(), JE = needle.size();
  if (JE == 0)
    return 0;
  if (JE > IE)
    return -1;
  auto Next = getNext(needle);
  int I = 0, J = 0;
  while (I != IE && J != JE) {
    while (J != -1 && haystack[I] != needle[J])
      J = Next[J];
    ++I;
    ++J;
  }
  return J == JE ? I - J : -1;
}
