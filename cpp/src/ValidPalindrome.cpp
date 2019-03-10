#include "ValidPalindrome.h"

using namespace lcpp;

bool Solution125_1::isPalindrome(std::string s) {
  if (s.empty())
    return true;
  auto I = s.cbegin(), J = s.cend() - 1;
  while (I < J) {
    if (!isalnum(*I)) {
      ++I;
    } else if (!isalnum(*J)) {
      --J;
    } else if (tolower(*I) != tolower(*J)) {
      return false;
    } else {
      ++I;
      --J;
    }
  }
  return true;
}
