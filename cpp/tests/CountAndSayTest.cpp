#include "CountAndSay.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(CountAndSay, Solution38_1) {
  auto S38_1 = Solution38_1();

  EXPECT_EQ("1", S38_1.countAndSay(1));
  EXPECT_EQ("1211", S38_1.countAndSay(4));
}