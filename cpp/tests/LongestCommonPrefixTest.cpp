#include "LongestCommonPrefix.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LongestCommonPrefix, Solution14_1) {
  std::vector<std::string> Strs1{
      "flower", "flow", "flight"
  };
  const std::string Expected1 = "fl";
  EXPECT_EQ(Expected1, Solution14_1().longestCommonPrefix(Strs1));

  std::vector<std::string> Strs2{
      "dog", "racecar", "car"
  };
  const std::string Expected2;
  EXPECT_EQ(Expected2, Solution14_1().longestCommonPrefix(Strs2));
}