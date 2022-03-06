#include "PalindromePartitioning.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PalindromePartitioning, Solution131_1) {
  auto S131_1 = Solution131_1();

  std::string const S1 = "aab";
  std::vector<std::vector<std::string>> const Expected1{{"a", "a", "b"},
                                                        {"aa", "b"}};
  EXPECT_EQ(Expected1, S131_1.partition(S1));

  std::string const S2 = "a";
  std::vector<std::vector<std::string>> const Expected2{{"a"}};
  EXPECT_EQ(Expected2, S131_1.partition(S2));
}