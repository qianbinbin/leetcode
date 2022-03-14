#include "WordBreak.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WordBreak, Solution139_1) {
  auto S132_1 = Solution132_1();

  std::string const S1 = "leetcode";
  std::vector<std::string> WordDict1{"leet", "code"};
  EXPECT_TRUE(S132_1.wordBreak(S1, WordDict1));

  std::string const S2 = "applepenapple";
  std::vector<std::string> WordDict2{"apple", "pen"};
  EXPECT_TRUE(S132_1.wordBreak(S2, WordDict2));

  std::string const S3 = "catsandog";
  std::vector<std::string> WordDict3{"cats", "dog", "sand", "and", "cat"};
  EXPECT_FALSE(S132_1.wordBreak(S3, WordDict3));
}
