#include "CountAndSay.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(CountAndSay, Solution38_1) {
  const int N1 = 1;
  const std::string Expected1 = "1";
  EXPECT_EQ(Expected1, Solution38_1().countAndSay(N1));

  const int N2 = 4;
  const std::string Expected2 = "1211";
  EXPECT_EQ(Expected2, Solution38_1().countAndSay(N2));
}