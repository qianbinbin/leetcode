#include "TwoSum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(TwoSum, Solution1_1) {
  std::vector<int> Nums{2, 7, 11, 15};
  const int Target = 9;
  const std::vector<int> Expected{0, 1};
  EXPECT_EQ(Expected, Solution1_1().twoSum(Nums, Target));
}