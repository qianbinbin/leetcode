#include "ImplementStrStr.h"
#include <cassert>
#include <limits>

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
