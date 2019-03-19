#include "LongestSubstringWithoutRepeatingCharacters.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LongestSubstringWithoutRepeatingCharacters, Solution3_1) {
  const std::string S1 = "abcabcbb";
  const int Expected1 = 3;
  EXPECT_EQ(Expected1, Solution3_1().lengthOfLongestSubstring(S1));

  const std::string S2 = "bbbbb";
  const int Expected2 = 1;
  EXPECT_EQ(Expected2, Solution3_1().lengthOfLongestSubstring(S2));

  const std::string S3 = "pwwkew";
  const int Expected3 = 3;
  EXPECT_EQ(Expected3, Solution3_1().lengthOfLongestSubstring(S3));
}