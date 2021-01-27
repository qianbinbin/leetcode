#include "ContainerWithMostWater.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ContainerWithMostWater, Solution11_1) {
  auto S11_1 = Solution11_1();

  std::vector<int> Height1{1, 8, 6, 2, 5, 4, 8, 3, 7};
  const int Expected1 = 49;
  EXPECT_EQ(Expected1, S11_1.maxArea(Height1));

  std::vector<int> Height2{1, 1};
  const int Expected2 = 1;
  EXPECT_EQ(Expected2, S11_1.maxArea(Height2));

  std::vector<int> Height3{4, 3, 2, 1, 4};
  const int Expected3 = 16;
  EXPECT_EQ(Expected3, S11_1.maxArea(Height3));

  std::vector<int> Height4{1, 2, 1};
  const int Expected4 = 2;
  EXPECT_EQ(Expected4, S11_1.maxArea(Height4));
}