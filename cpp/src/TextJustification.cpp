#include "TextJustification.h"

using namespace lcpp;

std::vector<std::string>
Solution68_1::fullJustify(std::vector<std::string> &words, int maxWidth) {
  std::vector<std::string> Result;
  auto I = words.cbegin(), J = I, E = words.cend();
  typedef std::string::size_type SizeType;
  SizeType LineWidth, WordWidth, SpaceWidth, Space, ExtraSpace;
  while (I != E) {
    LineWidth = (*I).size();
    J = I + 1;
    while (J != E && LineWidth + (WordWidth = (*J).size()) + 1 <= maxWidth) {
      LineWidth += WordWidth + 1;
      ++J;
    }
    Result.emplace_back(*I++);
    auto &Line = Result.back();
    if (J == I || J == E) {
      while (I != J)
        Line += ' ' + *I++;
      Line.resize(static_cast<SizeType>(maxWidth), ' ');
    } else {
      SpaceWidth = static_cast<SizeType>(maxWidth - LineWidth + J - I);
      Space = SpaceWidth / (J - I);
      ExtraSpace = SpaceWidth % (J - I);
      while (ExtraSpace-- != 0)
        Line += std::string(Space + 1, ' ') + *I++;
      while (I != J)
        Line += std::string(Space, ' ') + *I++;
    }
  }
  return Result;
}
