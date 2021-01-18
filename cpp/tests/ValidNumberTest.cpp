#include "ValidNumber.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ValidNumber, Solution65_1) {
  EXPECT_TRUE(Solution65_1().isNumber("0"));
  EXPECT_TRUE(Solution65_1().isNumber(" 0.1 "));
  EXPECT_FALSE(Solution65_1().isNumber("abc"));
  EXPECT_FALSE(Solution65_1().isNumber("1 a"));
  EXPECT_TRUE(Solution65_1().isNumber("2e10"));
  EXPECT_TRUE(Solution65_1().isNumber(" -90e3   "));
  EXPECT_FALSE(Solution65_1().isNumber(" 1e"));
  EXPECT_FALSE(Solution65_1().isNumber("e3"));
  EXPECT_TRUE(Solution65_1().isNumber(" 6e-1"));
  EXPECT_FALSE(Solution65_1().isNumber(" 99e2.5 "));
  EXPECT_TRUE(Solution65_1().isNumber("53.5e93"));
  EXPECT_FALSE(Solution65_1().isNumber(" --6 "));
  EXPECT_FALSE(Solution65_1().isNumber("-+3"));
  EXPECT_FALSE(Solution65_1().isNumber("95a54e53"));
}