#include "WordBreak.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WordBreak, Solution139_1) {
  const std::string S1 = "leetcode";
  std::vector<std::string> WordDict1{"leet", "code"};
  EXPECT_TRUE(Solution132_1().wordBreak(S1, WordDict1));

  const std::string S2 = "applepenapple";
  std::vector<std::string> WordDict2{"apple", "pen"};
  EXPECT_TRUE(Solution132_1().wordBreak(S2, WordDict2));

  const std::string S3 = "catsandog";
  std::vector<std::string> WordDict3{"cats", "dog", "sand", "and", "cat"};
  EXPECT_FALSE(Solution132_1().wordBreak(S3, WordDict3));
}
