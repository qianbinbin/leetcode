#include "CountAndSay.h"

using namespace lcpp;

std::string Solution38_1::countAndSay(int n) {
  std::string Result = "1", Tmp;
  char Count;
  while (n-- > 1) {
    auto I = Result.begin(), E = Result.end();
    while (I != E) {
      Count = '1';
      while (I + 1 != E && *(I + 1) == *I) {
        ++I;
        ++Count;
      }
      Tmp.push_back(Count);
      Tmp.push_back(*I);
      ++I;
    }
    std::swap(Result, Tmp);
    Tmp.clear();
  }
  return Result;
}
