#include "MinimumWindowSubstring.h"
#include <array>
#include <limits>

using namespace lcpp;

#define UC(Ch) (static_cast<unsigned char>(Ch))

std::string Solution76_1::minWindow(std::string s, std::string t) {
  const auto &Size1 = s.size(), &Size2 = t.size();
  if (Size1 < Size2)
    return "";
  typedef std::string::size_type SizeType;
  std::array<int, 256> Expected{};
  for (auto Ch : t)
    ++Expected[UC(Ch)];
  SizeType MinFirst = 0, Max = std::numeric_limits<SizeType>::max(),
      MinSize = Max;
  for (SizeType First = 0, Last = 0, ExpectedCount = 0; Last != Size1;) {
    if (Expected[UC(s[Last++])]-- > 0)
      ++ExpectedCount;
    while (ExpectedCount == Size2) {
      if (Last - First < MinSize)
        MinSize = Last - (MinFirst = First);
      if (++Expected[UC(s[First++])] > 0)
        --ExpectedCount;
    }
  }
  if (MinSize == Max)
    return "";
  return s.substr(MinFirst, MinSize);
}
