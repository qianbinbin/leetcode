#include "JumpGameII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(JumpGameII, Solution45_1) {
  std::vector<int> Nums{2, 3, 1, 1, 4};
  const int Expected = 2;
  EXPECT_EQ(Expected, Solution45_1().jump(Nums));
}
