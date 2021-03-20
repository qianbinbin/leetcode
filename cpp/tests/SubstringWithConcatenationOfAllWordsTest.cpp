#include "SubstringWithConcatenationOfAllWords.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SubstringWithConcatenationOfAllWords, Solution30_1) {
  auto S30_1 = Solution30_1();

  std::string const S1 = "barfoothefoobarman";
  std::vector<std::string> Words1{"foo", "bar"};
  std::vector<int> const Expected1{0, 9};
  EXPECT_EQ(Expected1, S30_1.findSubstring(S1, Words1));

  std::string const S2 = "wordgoodgoodgoodbestword";
  std::vector<std::string> Words2{"word", "good", "best", "word"};
  std::vector<int> const Expected2;
  EXPECT_EQ(Expected2, S30_1.findSubstring(S2, Words2));

  std::string const S3 = "barfoofoobarthefoobarman";
  std::vector<std::string> Words3{"bar", "foo", "the"};
  std::vector<int> const Expected3{6, 9, 12};
  EXPECT_EQ(Expected3, S30_1.findSubstring(S3, Words3));
}