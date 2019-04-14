#include "GrayCode.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(GrayCode, Solution89_1) {
  const int N1 = 2;
  std::vector<int> Expected1{0, 1, 3, 2};
  EXPECT_EQ(Expected1, Solution89_1().grayCode(N1));

  const int N2 = 0;
  std::vector<int> Expected2{0};
  EXPECT_EQ(Expected2, Solution89_1().grayCode(N2));
}