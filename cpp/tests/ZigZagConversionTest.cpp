#include "ZigZagConversion.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ZigZagConversion, Solution6_1) {
  auto S6_1 = Solution6_1();

  EXPECT_EQ("PAHNAPLSIIGYIR", S6_1.convert("PAYPALISHIRING", 3));
  EXPECT_EQ("PINALSIGYAHRPI", S6_1.convert("PAYPALISHIRING", 4));
  EXPECT_EQ("A", S6_1.convert("A", 1));
}