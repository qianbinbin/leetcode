#include "EditDistance.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(EditDistance, Solution72_1) {
  const std::string Word11 = "horse", Word12 = "ros";
  const int Expected1 = 3;
  EXPECT_EQ(Expected1, Solution72_1().minDistance(Word11, Word12));

  const std::string Word21 = "intention", Word22 = "execution";
  const int Expected2 = 5;
  EXPECT_EQ(Expected2, Solution72_1().minDistance(Word21, Word22));
}
