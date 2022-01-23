#include "MinimumWindowSubstring.h"
#include <array>
#include <limits>

using namespace lcpp;

std::string Solution76_1::minWindow(std::string s, std::string t) {
  const auto &Size1 = s.size(), &Size2 = t.size();
  typedef std::string::size_type SizeType;
  std::array<SizeType, 128> Expected{};
  for (auto Ch : t)
    ++Expected[Ch];
  SizeType Start = -1, Len = std::numeric_limits<SizeType>::max(); // -1 == max
  for (SizeType I = 0, J = 0, ExpectedCount = 0; J != Size1; ++J) {
    if (Expected[s[J]]-- > 0)
      ++ExpectedCount;
    for (; ExpectedCount == Size2; ++I) {
      if (J - I + 1 < Len)
        Len = J - (Start = I) + 1;
      if (++Expected[s[I]] > 0)
        --ExpectedCount;
    }
  }
  if (Start == -1)
    return "";
  return s.substr(Start, Len);
}
