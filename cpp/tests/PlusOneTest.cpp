#include "PlusOne.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PlusOne, Solution66_1) {
  auto S66_1 = Solution66_1();

  std::vector<int> Digits1{1, 2, 3};
  const std::vector<int> Expected1{1, 2, 4};
  EXPECT_EQ(Expected1, S66_1.plusOne(Digits1));

  std::vector<int> Digits2{4, 3, 2, 1};
  const std::vector<int> Expected2{4, 3, 2, 2};
  EXPECT_EQ(Expected2, S66_1.plusOne(Digits2));

  std::vector<int> Digits3{9};
  const std::vector<int> Expected3{1, 0};
  EXPECT_EQ(Expected3, S66_1.plusOne(Digits3));
}