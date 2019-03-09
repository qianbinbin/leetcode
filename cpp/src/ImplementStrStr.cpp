#include "ImplementStrStr.h"
#include <cassert>
#include <limits>
#include <vector>

using namespace lcpp;

int Solution28_1::strStr(std::string haystack, std::string needle) {
  const auto &Size1 = haystack.size(), &Size2 = needle.size();
  if (Size2 == 0)
    return 0;
  if (Size1 < Size2)
    return -1;
  std::string::size_type I, J, E = Size1 - Size2 + 1;
  for (I = 0; I != E; ++I) {
    for (J = 0; J != Size2; ++J) {
      if (haystack[I + J] != needle[J])
        break;
    }
    if (J == Size2) {
      assert(I <= std::numeric_limits<int>::max() && "Result overflow!");
      return static_cast<int>(I);
    }
  }
  return -1;
}

static void generateNext(const std::string &Str, std::vector<int> &Next) {
  const auto &Size = Str.size();
  if (Size == 0)
    return;
  assert(Size <= std::numeric_limits<int>::max());
  Next[0] = -1;
  int I = 1, J = -1, E = static_cast<int>(Size);
  while (I != E) {
    if (J == -1) {
      Next[I++] = 0;
      J = 0;
    } else if (Str[I - 1] == Str[J]) {
      if (Str[I] == Str[J + 1]) {
        Next[I++] = Next[++J];
      } else {
        Next[I++] = ++J;
      }
    } else {
      J = Next[J];
    }
  }
}

int Solution28_2::strStr(std::string haystack, std::string needle) {
  const auto &Size1 = haystack.size(), &Size2 = needle.size();
  if (Size2 == 0)
    return 0;
  if (Size1 < Size2)
    return -1;
  assert(Size1 <= std::numeric_limits<int>::max()
             && Size2 <= std::numeric_limits<int>::max());
  std::vector<int> Next(needle.size());
  generateNext(needle, Next);
  int I = 0, J = 0, EI = static_cast<int>(Size1),
      EJ = static_cast<int>(Size2);
  while (I != EI && J != EJ) {
    if (J == -1) {
      ++I;
      J = 0;
    } else if (haystack[I] != needle[J]) {
      J = Next[J];
    } else {
      ++I;
      ++J;
    }
  }
  return J == EJ ? I - J : -1;
}
