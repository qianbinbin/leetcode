#include "ScrambleString.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ScrambleString, Solution87_1) {
  auto S87_1 = Solution87_1();

  EXPECT_TRUE(S87_1.isScramble("great", "rgeat"));
  EXPECT_FALSE(S87_1.isScramble("abcde", "caebd"));
  EXPECT_TRUE(S87_1.isScramble("a", "a"));
}

TEST(ScrambleString, Solution87_2) {
  auto S87_2 = Solution87_2();

  EXPECT_TRUE(S87_2.isScramble("great", "rgeat"));
  EXPECT_FALSE(S87_2.isScramble("abcde", "caebd"));
  EXPECT_TRUE(S87_2.isScramble("a", "a"));
}
