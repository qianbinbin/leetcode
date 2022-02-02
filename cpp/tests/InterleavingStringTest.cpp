#include "InterleavingString.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(InterleavingString, Solution97_1) {
  auto S97_1 = Solution97_1();

  EXPECT_TRUE(S97_1.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
  EXPECT_FALSE(S97_1.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
  EXPECT_TRUE(S97_1.isInterleave("", "", ""));
}
