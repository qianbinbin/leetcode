#include "4Sum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FourSum, Solution18_1) {
  std::vector<int> Nums{1, 0, -1, 0, -2, 2};
  const int Target = 0;
  const std::vector<std::vector<int>> Expected{
      {-2, -1, 1, 2},
      {-2, 0, 0, 2},
      {-1, 0, 0, 1}
  };
  EXPECT_EQ(Expected, Solution18_1().fourSum(Nums, Target));
}