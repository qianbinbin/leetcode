#include "ImplementStrStr.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ImplementStrStr, Solution28_1) {
  std::string Haystack1 = "hello", Needle1 = "ll";
  const int Expected1 = 2;
  EXPECT_EQ(Expected1, Solution28_1().strStr(Haystack1, Needle1));

  std::string Haystack2 = "aaaaa", Needle2 = "bba";
  const int Expected2 = -1;
  EXPECT_EQ(Expected2, Solution28_1().strStr(Haystack2, Needle2));
}