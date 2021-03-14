#include "3SumClosest.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ThreeSumClosest, Solution16_1) {
  auto S16_1 = Solution16_1();

  std::vector<int> Nums1{-1, 2, 1, -4};
  int const Target1 = 1;
  int const Expected1 = 2;
  EXPECT_EQ(Expected1, S16_1.threeSumClosest(Nums1, Target1));
}