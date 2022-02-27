#include "ValidPalindrome.h"
#include <cctype>

using namespace lcpp;

bool Solution125_1::isPalindrome(std::string s) {
  auto I = s.begin(), J = s.end() - 1;
  while (I < J) {
    if (!std::isalnum(*I)) {
      ++I;
    } else if (!std::isalnum(*J)) {
      --J;
    } else if (std::tolower(*I) != std::tolower(*J)) {
      return false;
    } else {
      ++I;
      --J;
    }
  }
  return true;
}
