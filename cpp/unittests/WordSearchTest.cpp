#include "WordSearch.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WordSearch, Solution79_1) {
  std::vector<std::vector<char>> Board{
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}
  };
  EXPECT_TRUE(Solution79_1().exist(Board, "ABCCED"));
  EXPECT_TRUE(Solution79_1().exist(Board, "SEE"));
  EXPECT_FALSE(Solution79_1().exist(Board, "ABCB"));
}