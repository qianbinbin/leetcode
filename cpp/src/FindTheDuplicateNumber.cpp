#include "FindTheDuplicateNumber.h"

using namespace lcpp;

int Solution287_1::findDuplicate(std::vector<int> &nums) {
  int Slow = 0, Fast = 0;
  do {
    Slow = nums[Slow];
    Fast = nums[nums[Fast]];
  } while (Slow != Fast);
  int P = 0;
  while (Slow != P) {
    P = nums[P];
    Slow = nums[Slow];
  }
  return P;
}
