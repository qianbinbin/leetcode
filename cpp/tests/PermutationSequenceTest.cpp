#include "PermutationSequence.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PermutationSequence, Solution60_1) {
  auto S60_1 = Solution60_1();

  int const N1 = 3, K1 = 3;
  std::string const Expected1 = "213";
  EXPECT_EQ(Expected1, S60_1.getPermutation(N1, K1));

  int const N2 = 4, K2 = 9;
  std::string const Expected2 = "2314";
  EXPECT_EQ(Expected2, S60_1.getPermutation(N2, K2));

  int const N3 = 3, K3 = 1;
  std::string const Expected3 = "123";
  EXPECT_EQ(Expected3, S60_1.getPermutation(N3, K3));
}