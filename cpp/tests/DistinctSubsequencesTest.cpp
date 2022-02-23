#include "DistinctSubsequences.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(DistinctSubsequences, Solution115_1) {
  auto S115_1 = Solution115_1();

  EXPECT_EQ(3, S115_1.numDistinct("rabbbit", "rabbit"));
  EXPECT_EQ(5, S115_1.numDistinct("babgbag", "bag"));
}