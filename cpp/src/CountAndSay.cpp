#include "CountAndSay.h"
#include <cassert>

using namespace lcpp;

std::string Solution38_1::countAndSay(int n) {
  assert(1 <= n && n <= 30);
  std::string Result = "1", Tmp;
  int Count;
  for (int I = 1; I != n; ++I) {
    auto It = Result.cbegin(), E = Result.cend();
    while (It != E) {
      Count = 1;
      while (It + 1 != E && *(It + 1) == *It) {
        ++It;
        ++Count;
      }
      Tmp.push_back(static_cast<char>(Count + '0'));
      Tmp.push_back(*It);
      ++It;
    }
    std::swap(Result, Tmp);
    Tmp.clear();
  }
  return Result;
}
