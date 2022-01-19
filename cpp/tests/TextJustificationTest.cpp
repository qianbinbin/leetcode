#include "TextJustification.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(TextJustification, Solution68_1) {
  auto S68_1 = Solution68_1();

  std::vector<std::string> Words1{
      "This", "is", "an", "example", "of", "text", "justification."
  };
  const int MaxWidth1 = 16;
  const std::vector<std::string> Expected1{
      "This    is    an",
      "example  of text",
      "justification.  "
  };
  EXPECT_EQ(Expected1, S68_1.fullJustify(Words1, MaxWidth1));

  std::vector<std::string> Words2{
      "What", "must", "be", "acknowledgment", "shall", "be"
  };
  const int MaxWidth2 = 16;
  const std::vector<std::string> Expected2{
      "What   must   be",
      "acknowledgment  ",
      "shall be        "
  };
  EXPECT_EQ(Expected2, S68_1.fullJustify(Words2, MaxWidth2));

  std::vector<std::string> Words3{
      "Science", "is", "what", "we", "understand", "well", "enough", "to",
      "explain", "to", "a", "computer.", "Art", "is", "everything", "else",
      "we", "do"
  };
  const int MaxWidth3 = 20;
  const std::vector<std::string> Expected3{
      "Science  is  what we",
      "understand      well",
      "enough to explain to",
      "a  computer.  Art is",
      "everything  else  we",
      "do                  "
  };
  EXPECT_EQ(Expected3, S68_1.fullJustify(Words3, MaxWidth3));
}