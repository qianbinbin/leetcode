#include "TrappingRainWater.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(TrappingRainWater, Solution42_1) {
  auto S42_1 = Solution42_1();

  std::vector<int> Height1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int const Expected1 = 6;
  EXPECT_EQ(Expected1, S42_1.trap(Height1));

  std::vector<int> Height2{4, 2, 0, 3, 2, 5};
  int const Expected2 = 9;
  EXPECT_EQ(Expected2, S42_1.trap(Height2));
}

TEST(TrappingRainWater, Solution42_2) {
  auto S42_2 = Solution42_2();

  std::vector<int> Height1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int const Expected1 = 6;
  EXPECT_EQ(Expected1, S42_2.trap(Height1));

  std::vector<int> Height2{4, 2, 0, 3, 2, 5};
  int const Expected2 = 9;
  EXPECT_EQ(Expected2, S42_2.trap(Height2));
}

TEST(TrappingRainWater, Solution42_3) {
  auto S42_3 = Solution42_3();

  std::vector<int> Height1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int const Expected1 = 6;
  EXPECT_EQ(Expected1, S42_3.trap(Height1));

  std::vector<int> Height2{4, 2, 0, 3, 2, 5};
  int const Expected2 = 9;
  EXPECT_EQ(Expected2, S42_3.trap(Height2));
}