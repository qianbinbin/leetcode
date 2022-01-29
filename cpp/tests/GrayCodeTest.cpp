#include "GrayCode.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(GrayCode, Solution89_1) {
  auto S89_1 = Solution89_1();

  const int N1 = 2;
  std::vector<int> Expected1{0, 1, 3, 2};
  EXPECT_EQ(Expected1, S89_1.grayCode(N1));

  const int N2 = 1;
  std::vector<int> Expected2{0, 1};
  EXPECT_EQ(Expected2, S89_1.grayCode(N2));
}

TEST(GrayCode, Solution89_2) {
  auto S89_2 = Solution89_2();

  const int N1 = 2;
  std::vector<int> Expected1{0, 1, 3, 2};
  EXPECT_EQ(Expected1, S89_2.grayCode(N1));

  const int N2 = 1;
  std::vector<int> Expected2{0, 1};
  EXPECT_EQ(Expected2, S89_2.grayCode(N2));
}
