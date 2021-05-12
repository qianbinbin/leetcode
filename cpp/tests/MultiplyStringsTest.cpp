#include "MultiplyStrings.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MultiplyStrings, Solution43_1) {
  auto S43_1 = Solution43_1();

  EXPECT_EQ("6", S43_1.multiply("2", "3"));
  EXPECT_EQ("56088", S43_1.multiply("123", "456"));
}
