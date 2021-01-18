#include "ScrambleString.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ScrambleString, Solution87_1) {
  EXPECT_TRUE(Solution87_1().isScramble("great", "rgeat"));
  EXPECT_FALSE(Solution87_1().isScramble("abcde", "caebd"));
}

TEST(ScrambleString, Solution87_2) {
  EXPECT_TRUE(Solution87_2().isScramble("great", "rgeat"));
  EXPECT_FALSE(Solution87_2().isScramble("abcde", "caebd"));
}
