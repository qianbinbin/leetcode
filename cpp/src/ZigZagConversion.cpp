#include "ZigZagConversion.h"
#include <cassert>

using namespace lcpp;

std::string Solution6_1::convert(std::string s, int numRows) {
  assert(numRows > 0);
  typedef std::string::size_type SizeType;
  const SizeType Size = s.size(), Row = static_cast<SizeType>(numRows),
      Cycle = 2 * (Row - 1);
  if (Row == 1 || Size <= Row)
    return s;
  std::string Result(Size, 0);
  auto It = Result.begin();
  SizeType Index;
  for (Index = 0; Index < Size; Index += Cycle)
    *It++ = s[Index];
  for (SizeType I = 1, Offset; I < Row - 1; ++I) {
    Offset = 2 * (Row - 1 - I);
    for (Index = I; Index < Size; Index += Cycle) {
      *It++ = s[Index];
      if (Index + Offset < Size)
        *It++ = s[Index + Offset];
    }
  }
  for (Index = Row - 1; Index < Size; Index += Cycle)
    *It++ = s[Index];
  return Result;
}
