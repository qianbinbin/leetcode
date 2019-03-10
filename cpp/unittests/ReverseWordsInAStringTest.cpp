#include "ReverseWordsInAString.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ReverseWordsInAString, Solution151_1) {
  std::string S1 = "the sky is blue";
  const std::string Expected1 = "blue is sky the";
  EXPECT_EQ(Expected1, Solution151_1().reverseWords(S1));

  std::string S2 = "  hello world!  ";
  const std::string Expected2 = "world! hello";
  EXPECT_EQ(Expected2, Solution151_1().reverseWords(S2));

  std::string S3 = "a good   example";
  const std::string Expected3 = "example good a";
  EXPECT_EQ(Expected3, Solution151_1().reverseWords(S3));
}