#include "ValidNumber.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ValidNumber, Solution65_1) {
  auto S65_1 = Solution65_1();

  EXPECT_TRUE(S65_1.isNumber("0"));
  EXPECT_FALSE(S65_1.isNumber("e"));
  EXPECT_FALSE(S65_1.isNumber("."));
}