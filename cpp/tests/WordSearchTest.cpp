#include "WordSearch.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WordSearch, Solution79_1) {
  auto S79_1 = Solution79_1();

  std::vector<std::vector<char>> Board1{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  EXPECT_TRUE(S79_1.exist(Board1, "ABCCED"));
  EXPECT_TRUE(S79_1.exist(Board1, "SEE"));
  EXPECT_FALSE(S79_1.exist(Board1, "ABCB"));
}