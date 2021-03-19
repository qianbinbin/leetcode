#include "ImplementStrStr.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ImplementStrStr, Solution28_1) {
  auto S28_1 = Solution28_1();

  EXPECT_EQ(2, S28_1.strStr("hello", "ll"));
  EXPECT_EQ(-1, S28_1.strStr("aaaaa", "bba"));
  EXPECT_EQ(0, S28_1.strStr("", ""));
}

TEST(ImplementStrStr, Solution28_2) {
  auto S28_2 = Solution28_2();

  EXPECT_EQ(2, S28_2.strStr("hello", "ll"));
  EXPECT_EQ(-1, S28_2.strStr("aaaaa", "bba"));
  EXPECT_EQ(0, S28_2.strStr("", ""));
}
