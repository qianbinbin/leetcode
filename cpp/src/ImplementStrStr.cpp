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
  int I = 0, J = -1;
  while (I < Size - 1) {
    while (J != -1 && Str[J] != Str[I])
      J = Next[J];
    ++I;
    ++J;
    Next[I] = Str[J] == Str[I] ? Next[J] : J;
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
