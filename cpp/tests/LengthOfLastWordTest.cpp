#include "LengthOfLastWord.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LengthOfLastWord, Solution58_1) {
  auto S58_1 = Solution58_1();

  const std::string S = "Hello World";
  const int Expected = 5;
  EXPECT_EQ(Expected, S58_1.lengthOfLastWord(S));
}