#include "EditDistance.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(EditDistance, Solution72_1) {
  auto S72_1 = Solution72_1();

  EXPECT_EQ(3, S72_1.minDistance("horse", "ros"));
  EXPECT_EQ(5, S72_1.minDistance("intention", "execution"));
}
