#include "SubstringWithConcatenationOfAllWords.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SubstringWithConcatenationOfAllWords, Solution30_1) {
  const std::string S1 = "barfoothefoobarman";
  std::vector<std::string> Words1{"foo", "bar"};
  const std::vector<int> Expected1{0, 9};
  EXPECT_EQ(Expected1, Solution30_1().findSubstring(S1, Words1));

  const std::string S2 = "wordgoodgoodgoodbestword";
  std::vector<std::string> Words2{"word", "good", "best", "word"};
  const std::vector<int> Expected2;
  EXPECT_EQ(Expected2, Solution30_1().findSubstring(S2, Words2));
}