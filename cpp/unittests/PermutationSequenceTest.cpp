#include "PermutationSequence.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PermutationSequence, Solution60_1) {
  const int N1 = 3, K1 = 3;
  const std::string Expected1 = "213";
  EXPECT_EQ(Expected1, Solution60_1().getPermutation(N1, K1));

  const int N2 = 4, K2 = 9;
  const std::string Expected2 = "2314";
  EXPECT_EQ(Expected2, Solution60_1().getPermutation(N2, K2));
}