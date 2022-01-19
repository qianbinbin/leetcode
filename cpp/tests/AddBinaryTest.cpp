#include "AddBinary.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(AddBinary, Solution67_1) {
  auto S67_1 = Solution67_1();

  EXPECT_EQ("100", S67_1.addBinary("11", "1"));
  EXPECT_EQ("10101", S67_1.addBinary("1010", "1011"));
}