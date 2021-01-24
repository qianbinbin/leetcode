#include "ReverseInteger.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ReverseInteger, Solution7_1) {
  auto S7_1 = Solution7_1();

  EXPECT_EQ(321, S7_1.reverse(123));
  EXPECT_EQ(-321, S7_1.reverse(-123));
  EXPECT_EQ(21, S7_1.reverse(120));
  EXPECT_EQ(0, S7_1.reverse(0));
}
