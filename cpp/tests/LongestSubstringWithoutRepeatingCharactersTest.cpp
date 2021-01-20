#include "LongestSubstringWithoutRepeatingCharacters.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LongestSubstringWithoutRepeatingCharacters, Solution3_1) {
  auto S3_1 = Solution3_1();

  EXPECT_EQ(3, S3_1.lengthOfLongestSubstring("abcabcbb"));
  EXPECT_EQ(1, S3_1.lengthOfLongestSubstring("bbbbb"));
  EXPECT_EQ(3, S3_1.lengthOfLongestSubstring("pwwkew"));
  EXPECT_EQ(0, S3_1.lengthOfLongestSubstring(""));
}