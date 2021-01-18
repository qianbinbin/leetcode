#include "InterleavingString.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(InterleavingString, Solution97_1) {
  EXPECT_TRUE(Solution97_1().isInterleave("aabcc", "dbbca", "aadbbcbcac"));
  EXPECT_FALSE(Solution97_1().isInterleave("aabcc", "dbbca", "aadbbbaccc"));
}
