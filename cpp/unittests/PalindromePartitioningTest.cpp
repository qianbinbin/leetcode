#include "PalindromePartitioning.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PalindromePartitioning, Solution131_1) {
  const std::string S = "aab";
  const std::vector<std::vector<std::string>> Expected{{"a", "a", "b"},
                                                       {"aa", "b"}};
  EXPECT_EQ(Expected, Solution131_1().partition(S));
}