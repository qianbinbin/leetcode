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

int Solution287_2::findDuplicate(std::vector<int> &nums) {
  int Low = 1, High = nums.size() - 1, Mid, Count;
  while (Low <= High) {
    Mid = Low + (High - Low) / 2;
    Count = 0;
    for (const auto &N : nums) {
      if (N <= Mid)
        ++Count;
    }
    if (Count <= Mid)
      Low = Mid + 1;
    else
      High = Mid - 1;
  }
  return Low;
}
